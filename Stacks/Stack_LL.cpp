#include<iostream>
using namespace std;

template<typename T>
class Node
{
	public:
		T data;
		Node<T>*next;
		
		Node(T x)
		{
			this->data=x;
			this->next=NULL;
		}
};

template<typename T>
class Stack
{
	Node<T>*head;
	int size;
	int capacity;
	public:
		Stack(int osize)
		{
			head=NULL;
			size=0;
			capacity=osize;
		}
		
		bool isEmpty()
		{
			if (head==NULL)
				return true;
			else
				return false;
		}
		
		bool isFull()
		{
			if(capacity==size)
				return true;
			else
				return false;
		}
		
		void push(T element)
		{
			if(isFull())
			{
				cout<<"Stack is Full."<<endl;
				return;
			}
			Node<T>*newNode=new Node<T>(element);
			newNode->next=head;
			head=newNode;
			size++;
		}
		
		T top()
		{
			if(isEmpty())
			{
				cout<<"Stack is Empty."<<endl;
				return 6969;
			}
			return head->data;
		}
		
		T pop()
		{
			if(isEmpty())
			{
				cout<<"Stack is Empty."<<endl;
				return 6969;
			}
			Node<T>*temp=head;
			T ans=head->data;
			head=head->next;
			size--;
			delete temp;
			return ans;
		}
		
		void print()
		{
			Node<T>*temp=head;
			while(temp!=NULL)
			{
				cout<<temp->data<<endl;
				temp=temp->next;
			}
			return;
		}
};

int main()
{
	Stack<int> s1(5);
	s1.push(1);
	cout<<s1.top()<<endl;
	s1.push(2);
	s1.push(3);
	cout<<s1.top()<<endl;
	s1.push(4);
	s1.push(5);
	cout<<s1.top()<<endl;
	
	s1.print();
	s1.pop();
	s1.print();
	s1.pop();
	s1.pop();
	s1.pop();
	s1.pop();
	s1.pop();
	s1.push(69);
	s1.push(96);
	s1.print();
}
