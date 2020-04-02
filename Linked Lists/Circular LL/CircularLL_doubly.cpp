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
	Node*head=NULL;
	Node*tail=NULL;
	int d;
	cout<<"Enter Data : ";
	cin>>d;
	while(d!=-1)
	{
		Node*newNode=new Node(d);
		if(head==NULL)
		{
			head=newNode;
			tail=newNode;
			newNode->next=head;
			newNode->prev=head;
		}
		else
		{
			tail->next=newNode;
			newNode->prev=tail;
			newNode->next=head;
			head->prev=newNode;
			tail=newNode;
		}
		cout<<"Enter Data : ";
		cin>>d;
	}
	return head;
}

void printCDLL(Node*head)
{
	Node*temp=head;
	while(temp->next!=head)
	{
		cout<<temp->data<<"=";
		temp=temp->next;
	}
	cout<<temp->data<<"=";
	cout<<temp->next->data;
	cout<<endl;
}

Node* insertBeg(Node*head)
{
	int d;
	cout<<"Enter element data : ";
	cin>>d;
	Node*newNode=new Node(d);
	
	newNode->next=head;
	newNode->prev=head->prev;
	head->prev->next=newNode;
	head->prev=newNode;
	head=newNode;
	return head;
}

Node* insertEnd(Node*head)
{
	int d;
	cout<<"Enter element data : ";
	cin>>d;
	Node*newNode=new Node(d);
	
	newNode->next=head;
	newNode->prev=head->prev;
	head->prev->next=newNode;
	head->prev=newNode;
	return head;
}


Node* deleteBeg(Node*head)
{
	Node*temp=head;
	head->next->prev=head->prev;
	head->prev->next=head->next;
	head=head->next;
	delete temp;
	return head;
}

Node* deleteEnd(Node*head)
{
	Node*temp=head->prev;
	head->prev->prev->next=head;
	head->prev=head->prev->prev;
	delete temp;
	return head;
}


int main()
{
	cout<<endl;
	cout<<"------------------------------------------------------------------------"<<endl;
	cout<<"1.Insert at Beginning"<<endl;
	cout<<"2.Insert at End"<<endl;
	cout<<"3.Delete at Beginning"<<endl;
	cout<<"4.Delete at End"<<endl;
	cout<<"5.Delete Particular Element"<<endl;
	cout<<"-1.Exit"<<endl;
	cout<<"------------------------------------------------------------------------"<<endl;
	Node*head=takeInput();
	printCDLL(head);

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
					printCDLL(head);
				}	
				break;
			
			case 2:
				{
					head=insertEnd(head);
					printCDLL(head);
				}
				break;
				
			case 3:
				{
					head=deleteBeg(head);
					printCDLL(head);
				}	
				break;
				
			case 4:
				{
					head=deleteEnd(head);
					printCDLL(head);
				}	
				break;
				
			case -1:
				exit(1);
		}
		cout<<"Enter operation number : ";
		cin>>menu;
	}
}
