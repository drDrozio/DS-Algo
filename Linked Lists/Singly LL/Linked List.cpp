#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node* next;
		
	Node(int n)
	{
		data=n;
		this->next=NULL;
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
			tail=newNode;
		}
		else
		{
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
		cout<<temp->data<<"-";
		temp=temp->next;
	}
	cout<<temp->data<<endl;
}

Node* insertatithNode(Node*head,int index)
{
	int x;
	cout<<"Enter data : ";
	cin>>x;
	Node* newNode=new Node(x);
	//Insert at head
	if(index==0)
	{
		newNode->next=head;
		head=newNode;
	}
	//Insert at mid
	Node* temp=head;
	Node* prev=temp;
	int count=0;
	while(temp!=NULL && count!=index)
	{
		prev=temp;
		temp=temp->next;
		count++;
	}
	if(count==index)
	{
		prev->next=newNode;
		newNode->next=temp;
	}
	else
	{
		prev->next=newNode;
		newNode->next=NULL;
	}
	return head;
}

Node* deleteith(Node*head,int index)
{
	Node* newHead=head;
	if(index==0)
	{
		Node*temp=newHead;
		newHead=newHead->next;
		delete temp;
		return newHead;
	}
	else
	{
		Node*temp=newHead;
		Node*prev=temp;
		int count=0;
		while(temp!=NULL && count!=index)
		{
			prev=temp;
			temp=temp->next;
			count++;
		}
		if(count==index)
		{
			prev->next=temp->next;
			delete temp;
			return newHead;
		}
		else
		{
			prev->next=NULL;
			delete temp;
		}
	}
	return newHead;
}

Node* reverseLL1(Node*head)
{
	Node*tempHead=head;
	Node*tail=head;
	//Finding size of LL
	int size=0;
	while(tail!=NULL)
	{
		size++;
		tail=tail->next;
	}
	
	for(int i=0;i<(size/2);i++)
	{
		tail=tempHead;
		int j=i+1;
		while(j<(size-i))
		{
			tail=tail->next;
			j++;
		}
		int temp=tail->data;
		tail->data=tempHead->data;
		tempHead->data=temp;
		tempHead=tempHead->next;
	}
	return head;
}

int LengthRecHelper(Node*temp)
{
	if(temp==NULL)
		return 0;
	
	return 1+LengthRecHelper(temp->next);
} 

int LengthRec(Node*head)
{
	Node*temp=head;
	return LengthRecHelper(temp);
}

Node* insertRecHelper(Node*head,int i,int data)
{
	if(i==0)
	{
		Node* newNode=new Node(data);
		newNode->next=head;
		return newNode;
	}
	head->next=insertRecHelper(head->next,i-1,data);
	return head;
}

Node* insertRec(Node*head,int i,int data)
{
	Node*temp=head;
	head=insertRecHelper(temp,i,data);
	return head;
}

Node* DeleteRecHelper(Node*head,int i)
{
	if(i==0)
	{
		Node*ptr=head->next;
		delete head;
		return ptr;
	}
	head->next=DeleteRecHelper(head->next,i-1);
	return head;
}
Node* DeleteRec(Node*head,int i)
{
	Node*temp=head;
	head=DeleteRecHelper(temp,i);
	return head;
}

Node* appendLastNtoFirst(Node*head,int n)
{
	Node*temp=head;
	int count=1;
	while(temp->next!=NULL)
	{
		temp=temp->next;
		count++;
	}
	Node*last=temp;
	temp=head;
	int i=1;
	while(i<(count-n))
	{
		temp=temp->next;
		i++;
	}
	last->next=head;
	head=temp->next;
	temp->next=NULL;
	return head;
}

Node* eliminateDuplicates(Node*head)
{
	if(head==NULL || head->next==NULL)
		return head;	
	else
	{
		Node*prev=head;
	    Node*temp=head->next;
		while(temp!=NULL)
		{
			if(temp->data==prev->data)
			{
				Node*ptr=temp;
				prev->next=temp->next;
				temp=temp->next;
				delete ptr;
			}
			else
			{
				prev=temp;
				temp=temp->next;	
			}
		}
	}
	return head;
}

bool checkPalindrome(Node*head)
{
	Node*revHead=reverseLL1(head);
	Node*temp1=head;
	Node*temp2=revHead;
	
	while(temp1!=NULL)
	{
		if(temp1->data!=temp2->data)
			return false;
		else
		{
			temp1=temp1->next;
			temp2=temp2->next;
		}
	}
	return true;
}

int midLL(Node*head)
{
	Node*fast=head->next;
	Node*slow=head;
	
	while(fast!=NULL && fast->next!=NULL)
	{
		slow=slow->next;
		fast=(fast->next)->next;
	}
	int ans=slow->data;
	return ans;
}

Node* mergeTwo(Node*head1,Node*head2)
{
	Node*temp1=head1;
	Node*temp2=head2;
	Node*head=NULL;
	Node*tail=NULL;
	
	if(temp1->data<=temp2->data)
	{
		head=temp1;
		tail=temp1;
		temp1=temp1->next;
	}
	else
	{
		head=temp2;
		tail=temp2;
		temp2=temp2->next;
	}
	while(temp1!=NULL && temp2!=NULL)
	{
		if(temp1->data<=temp2->data)
		{
			tail->next=temp1;
			tail=temp1;
			temp1=temp1->next;
		}
		else
		{
			tail->next=temp2;
			tail=temp2;
			temp2=temp2->next;
		}
	}
	while(temp1==NULL && temp2!=NULL)
	{
		tail->next=temp2;
		tail=temp2;
		temp2=temp2->next;
	}
	while(temp1!=NULL && temp2==NULL)
	{
		tail->next=temp1;
		tail=temp1;
		temp1=temp1->next;
	}
	return head;
}

Node*reverseRec(Node*temp)
{
	if(temp->next==NULL)
	{
		return temp;
	}
	Node*newHead=reverseRec(temp->next);
	temp->next->next=temp;
	temp->next=NULL;
	return newHead;
}

Node* reverseLL2(Node*head)
{
	Node*pre=NULL;
	Node*cur=head;
	Node*nxt=head->next;
	
	while(cur!=NULL)
	{
		cur->next=pre;
		pre=cur;
		cur=nxt;
		if(nxt==NULL)
			nxt=NULL;
		else
			nxt=nxt->next;
	}
	return pre;
}

int returnIndexofN(Node*head,int x)
{
	if(head==NULL)
		return -6969;
	if(head->data==x)
		return 0;
		
	return 1+returnIndexofN(head->next,x);
}

Node* evenAfterOdd(Node*head)
{
	int odd[100]={0};
	int even[100]={0};
	int countOdd=0;
	int countEven=0;
	
	Node*temp=head;
	int count=0;
	while(temp!=NULL)
	{
		if((temp->data%2)!=0)
		{
			odd[countOdd]=temp->data;
			countOdd++;
		}
		else
		{
			even[countEven]=temp->data;
			countEven++;
		}
		count++;
		temp=temp->next;
	}
	temp=head;
	for(int i=0;i<countOdd;i++)
	{
		temp->data=odd[i];
		temp=temp->next;
	}
	for(int i=0;i<countEven;i++)
	{
		temp->data=even[i];
		temp=temp->next;
	}
	return head;
}

Node*deleteNAfterM(Node*head,int m,int n)
{
	Node*temp=head;
	while(temp!=NULL)
	{
		int i=0;
		while(i<m-1)
		{
			temp=temp->next;
			i++;
			if(temp==NULL || temp->next==NULL)
				break;
		}
		if(temp==NULL || temp->next==NULL)
				break;
				
		Node*ptr=temp->next;
		temp->next=NULL;
		
		int j=0;
		while(j<n)
		{
			Node*p=ptr;
			ptr=ptr->next;
			p->next=NULL;
			delete p;
			j++;
			if(ptr==NULL)
				break;
		}
		if(ptr==NULL)
			temp->next=NULL;
		else
		{
			temp->next=ptr;
			temp=ptr;
		}
	}
	return head;
}

int main()
{
	cout<<"########################## Single Linked List ##########################"<<endl;
	cout<<"-------------------------------------------------------------------------"<<endl;
	cout<<"| 1|Create Linked List                                                  |"<<endl;
	cout<<"| 2|Insert at Particular Index                                          |"<<endl;
	cout<<"| 3|Delete at Particular Index                                          |"<<endl;
	cout<<"| 4|Reverse Linked List using two pointers                              |"<<endl;
	cout<<"| 5|Length Recursively                                                  |"<<endl;
	cout<<"| 6|Insert Recursively at Particular Index                              |"<<endl;
	cout<<"| 7|Delete Recursively at Particular Index                              |"<<endl;
	cout<<"| 8|Append Last n elements to the beginning of Linked List              |"<<endl;
	cout<<"| 9|Eliminate duplicates from sorted Linked List                        |"<<endl;
	cout<<"|10|Check whether Linked List is Palindrome                             |"<<endl;
	cout<<"|11|Find Mid of Linked List                                             |"<<endl;
	cout<<"|12|Merge two Sorted Linked List                                        |"<<endl;
	cout<<"|13|Reverse Linked List iteratively                                     |"<<endl;
	cout<<"|14|Reverse Linked List recursively                                     |"<<endl;
	cout<<"|15|Find index of a node recursively in Linked List                     |"<<endl;
	cout<<"|16|Even after Odd in Linked List                                       |"<<endl;
	cout<<"|17|Retain m nodes then delete n nodes                                  |"<<endl;
	cout<<"|18|Swap mth and nth element in Linked List                             |"<<endl;
	cout<<"|19|Reverse first K elements then reverse next k elements and join so on|"<<endl;
	cout<<"|20|Bubble Sort Linked List                                             |"<<endl;
	cout<<"| 0|Exit                                                                |"<<endl;
	cout<<"-------------------------------------------------------------------------"<<endl;
	
	int num;
	cout<<"Enter operation number : ";
	cin>>num;
	Node* head=NULL;
	while(num!=0)
	{
		switch(num)
		{
			case 1:
				{
					head=takeInput();
					printLL(head);
					cout<<endl;
				}
				break;
			case 2:
				{
					int index;
					cout<<"Enter index of insertion : ";
					cin>>index;
					head=insertatithNode(head,index);
					printLL(head);
				}
				break;
				
			case 3:
				{
					int dIndex;
					cout<<"Enter index of deletion : ";
					cin>>dIndex;
					head=deleteith(head,dIndex);
					printLL(head);
				}
				break;
				
			case 4:
				{
					head=reverseLL1(head);
					printLL(head);
				}
				break;
				
			case 5:
				{
					int l=LengthRec(head);
					cout<<"Length of List= "<<l<<endl;
				}
				break;
			case 6:
				{
					int d,ind;
					cout<<"Enter data : ";
					cin>>d;
					cout<<"Enter index of insertion : ";
					cin>>ind;
					head=insertRec(head,ind,d);
					printLL(head);
				}
				break;
			case 7:
				{
					int i;
					cout<<"Enter index of deletion : ";
					cin>>i;
					head=DeleteRec(head,i);
					printLL(head);
				}
				break;
			case 8:
				{
					int n;
					cout<<"Enter value of n : ";
					cin>>n;
					head=appendLastNtoFirst(head,n);
					printLL(head);
				}
				break;
			case 9:
				{
					head=eliminateDuplicates(head);
					printLL(head);
				}
				break;
			case 10:
				{
					if(checkPalindrome(head)==1)
						cout<<"Is a Palindrome."<<endl;
					else
						cout<<"Not a Palindrome."<<endl;
				}
				break;
			case 11:
				{
					cout<<"Mid of Linked List : "<<midLL(head)<<endl;
				}
			case 12:
				{
					Node*head1=takeInput();
					printLL(head1);
					Node*head2=takeInput();
					printLL(head2);
					Node*head=mergeTwo(head1,head2);
					printLL(head);
				}
			case 13:
				{
					head=reverseLL2(head);
					cout<<"Reversed Linked List : ";
					printLL(head);
				}
			case 14:
				{
					head=reverseRec(head);
					printLL(head);
				}
			case 15:
				{
					int n;
					cout<<"Enter element : ";
					cin>>n;
					int index=returnIndexofN(head,n);
					cout<<index<<endl;
				}
			case 16:
				{
					cout<<"Even after Odd : ";
					head=evenAfterOdd(head);
					printLL(head);
				}
			case 17:
				{
					int m,n;
					cout<<"Enter nodes to be retained : ";
					cin>>m;
					cout<<"Enter nodes to be deleted : ";
					cin>>n;
					cout<<"Updated List : ";
					head=deleteNAfterM(head,m,n);
					printLL(head);
				}
		}
		cout<<"Enter operation number : ";
		cin>>num;
	}	
}

