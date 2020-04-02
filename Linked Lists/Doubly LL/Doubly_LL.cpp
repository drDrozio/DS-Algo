#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node* next;
		Node* prev;
	Node(int x)
	{
		this->data=x;
		this->next=NULL;
		this->prev=NULL;
	}
};

Node* takeInput()
{
	int d;
	cout<<"Enter data : ";
	cin>>d;
	Node* head=NULL;
	Node* tail=NULL;
	while(d!=-1)
	{
		Node* newNode=new Node(d);
		if(head==NULL)
		{
			head=newNode;
			newNode->prev=NULL;
			newNode->next=NULL;
			tail=newNode;
		}
		else
		{
			newNode->prev=tail;
			newNode->next=NULL;
			tail->next=newNode;
			tail=newNode;
		}
		cout<<"Enter data : ";
		cin>>d;
	}
	return head;
}

void printLL(Node*head)
{
	Node* temp=head;
	while(temp->next!=NULL)
	{
		cout<<temp->data<<"=";
		temp=temp->next;
	}
	cout<<temp->data;
}

void searchX(Node*head,int x)
{
	if(head==NULL)
		cout<<"List is Empty";
	Node*temp=head;
	while(temp!=NULL)
	{
		if(temp->data==x)
		{
			cout<<"Element present";
			return;
		}
		temp=temp->next;
	}
	cout<<"Element not present";
}

Node* push(Node*head,int x)
{
	Node*newNode=new Node(x);
	newNode->next=NULL;
	newNode->prev=NULL;
	if(head==NULL)
	{
		head=newNode;
		return head;
	}
	else
	{
		newNode->next=head;
		head=newNode;
		return head;
	}
}

Node* insert(Node*head,int e,int i)
{
	Node*newNode=new Node(i);
	newNode->prev=NULL;
	newNode->next=NULL;
	if(head==NULL)
	{
		head=newNode;
		return head;
	}
	else
	{
		Node*temp=head;
		while(temp->next!=NULL && temp->data!=e)
		{
			temp=temp->next;
		}
		if(temp->data==e)
		{
			newNode->next=temp->next;
			newNode->prev=temp;
			(temp->next)->prev=newNode;
			temp->next=newNode;
		}
		else
		{
			cout<<"Element not present in the list ";
		}
		return head;
	}
}

Node* append(Node*head,int a)
{
	Node*newNode=new Node(a);
	newNode->next=NULL;
	newNode->prev=NULL;
	if(head==NULL)
	{
		head=newNode;
		return head;
	}
	else
	{
		Node*temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		newNode->prev=temp;
		temp->next=newNode;
		return head;
	}
}

Node* delHead(Node*head)
{
	if(head==NULL)
	{
		cout<<"List is empty.";
		return head;
	}
	else
	{
		Node*temp=head;
		head=head->next;
		head->next->prev=NULL;
		delete temp;
		return head;
	}
}

Node* delX(Node*head,int x)
{
	if(head==NULL)
		return head;
	else
	{
		Node* temp=head;
		if(head->next==NULL && head->data==x)
		{
			head=NULL;
			delete temp;
			return head;
		}
		else
		{
			while(temp->next!=NULL && temp->data!=x)
			{
				temp=temp->next;
			} 
			if(temp->data==x)
			{
				temp->prev->next=temp->next;
				temp->next->prev=temp->prev;
				delete temp;
				return head;
			}
			cout<<endl<<"Element not present.";
			return head;
		}
	}
}

Node* delTail(Node*head)
{
	if(head==NULL)
	{
		cout<<"List is empty.";
		return head;
	}
	else
	{
		Node*temp=head;
		if(head->next==NULL)
		{
			head=NULL;
			delete temp;
			return head;
		}
		else
		{
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->prev->next=NULL;
			temp->prev=NULL;
			delete temp;
			return head;
		}
	}
}

int main()
{
	Node* head=takeInput();
	printLL(head);
	int x;
	cout<<endl<<"Enter element to be searched ";
	cin>>x;
	searchX(head,x);
	
	//Push
	int p;
	cout<<endl<<"Enter element to be pushed : ";
	cin>>p;
	head=push(head,p);
	printLL(head);
	
	//Insert at specific after specific
	int i;
	cout<<endl<<"Enter element to be inserted : ";
	cin>>i;
	int e;
	cout<<"Enter element after which insertion is done : ";
	cin>>e;
	head=insert(head,e,i);
	printLL(head);
	
	//Append
	int a;
	cout<<endl<<"Enter element to be appended : ";
	cin>>a;
	head=append(head,a);
	printLL(head);
	
	//Delete head
	head=delHead(head);
	cout<<endl;
	printLL(head);
	
	//Delete specific
	int d;
	cout<<endl<<"Enter element to be deleted : ";
	cin>>d;
	head=delX(head,d);
	printLL(head);
	
	//Delete tail
	head=delTail(head);
	cout<<endl;
	printLL(head);
}
