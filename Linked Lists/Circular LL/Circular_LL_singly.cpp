#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node* next;
	Node(int x)
	{
		this->data=x;
		this->next=NULL;
	}
};

Node* takeInput()
{
	Node*head=NULL;
	Node*tail=NULL;
	int d;
	cout<<"Enter data: ";
	cin>>d;
	while(d!=-1)
	{
		Node*newNode=new Node(d);
		if(head==NULL)
		{
			head=newNode;
			newNode->next=head;
			tail=newNode;
		}
		else
		{
			tail->next=newNode;
			newNode->next=head;
			tail=newNode;
		}
		cout<<"Enter data: ";
		cin>>d;
	}
	return head;
}

void printLL(Node*head)
{
	Node* temp=head;
	while(temp->next!=head)
	{
		cout<<temp->data<<"-";
		temp=temp->next;
	}
	cout<<temp->data;
	cout<<"-"<<temp->next->data;
	cout<<endl;
}

Node*insertBeg(Node*head)
{
	int e;
	cout<<"Enter element to be inserted: ";
	cin>>e;
	Node*newNode=new Node(e);
	
	if(head==NULL)
	{
		cout<<"List is empty."<<endl;
		head=newNode;
		newNode->next=head;
	}
	else
	{
		Node*temp=head;
		while(temp->next!=head)
		{
			temp=temp->next;
		}
		newNode->next=head;
		head=newNode;
		temp->next=head;
	}
	return head;
}

Node* insertEnd(Node*head)
{
	int e;
	cout<<"Enter element to be inserted: ";
	cin>>e;
	Node*newNode=new Node(e);
	
	if(head==NULL)
	{
		cout<<"List is empty."<<endl;
		head=newNode;
		newNode->next=head;
	}
	else
	{
		Node*temp=head;
		while(temp->next!=head)
		{
			temp=temp->next;
		}
		temp->next=newNode;
		newNode->next=head;
	}
	return head;
}

Node* deleteBeg(Node*head)
{
	if(head==NULL)
	{
		cout<<"List is empty."<<endl;
	}
	else
	{
		Node*tail=head;
		while(tail->next!=head)
		{
			tail=tail->next;
		}
		Node*temp=head;
		tail->next=head->next;
		head=head->next;
		delete temp;
	}
	return head;
}

Node* deleteEnd(Node*head)
{
	if(head==NULL)
	{
		cout<<"List is empty."<<endl;
	}
	else
	{
		Node*tail=head;
		Node*prev=head;
		while(tail->next!=head)
		{
			prev=tail;
			tail=tail->next;
		}
		prev->next=tail->next;
		delete tail;
	}
	return head;
}

int main()
{
	cout<<endl;
	cout<<"------------------------------------------------------------------------"<<endl;
	cout<<"Insert at Beginning -> 1"<<endl;
	cout<<"Insert at End -> 2"<<endl;
	cout<<"Delete at Beginning -> 3"<<endl;
	cout<<"Delete at End -> 4"<<endl;
	cout<<"Delete Particular Element -> 5"<<endl;
	cout<<"Exit -> -1"<<endl;
	cout<<"------------------------------------------------------------------------"<<endl;
	Node*head=takeInput();
	printLL(head);

	int menu;
	cout<<"Enter operation number : ";
	cin>>menu;
	while(menu!=-1)
	{
		switch(menu)
		{
			case 1:
				{
					head=insertBeg(head);
					printLL(head);
				}	
				break;
			
			case 2:
				{
					head=insertEnd(head);
					printLL(head);
				}
				break;
				
			case 3:
				{
					head=deleteBeg(head);
					printLL(head);
				}	
				break;
				
			case 4:
				{
					head=deleteEnd(head);
					printLL(head);
				}	
				break;
		}
		cout<<"Enter operation number : ";
		cin>>menu;
	}
}
