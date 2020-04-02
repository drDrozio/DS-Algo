#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node*next;
		
		Node(int x)
		{
			this->data=x;
			this->next=NULL;
		}
};

class Queue
{
	public:
		int size;
		Node*front;
		Node*rear;
		Queue()
		{
			front=NULL;
			rear=NULL;
		}
		
		bool isEmpty()
		{
			if(front==NULL)
				return true;
		}
		
		void enqueue(int d)
		{
			Node* newNode=new Node(d);
			if(isEmpty())
			{
				front=newNode;
				rear=newNode;
				return;
			}
			rear->next=newNode;
			rear=newNode;
			return;
		}
		
		int dequeue()
		{
			if(isEmpty())
			{
				cout<<endl<<"Queue is Empty.";
				return -6969;
			}
			Node*temp=front;
			int tempData=front->data;
			front=front->next;
			delete temp;
			return tempData;
		}
		
		int frontQ()
		{
			return front->data;
		}
		
		void printQueue()
		{
			Node*temp=rear;
			while(temp!=NULL)
			{
				cout<<temp->data<<endl;
				temp=temp->next;
			}
			cout<<temp->data<<endl;
		}
};


int main()
{
	Queue q1;
	q1.enqueue(10);
	q1.enqueue(20);
	q1.enqueue(30);
	q1.enqueue(40);
	q1.printQueue();
}
