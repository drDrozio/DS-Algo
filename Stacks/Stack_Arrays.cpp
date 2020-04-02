#include<iostream>
using namespace std;

class Stack
{
	int* data;
	int top;
	int capacity;
	
	public:
		Stack(int csize)
		{
			data=new int[csize];
			top=-1;
			capacity=csize;
		}
		
		bool isEmpty()
		{
			return top==-1;
		}
			
		bool isFull()
		{
			return top==capacity;
		}
			
		int topE()
		{
			if(isEmpty())
			{
				cout<<"Stack is empty.";
				return 6969;
			}
			return data[top];
		}
		
		void push(int element)
		{
			if(isFull())
			{
				cout<<"Stack is full.";
				return;
			}
			top++;
			data[top]=element;
			return;
		}
		
		int pop()
		{
			if(isEmpty())
			{
				cout<<"Stack is empty.";
				return 6969;
			}
			int ans=top;
			top--;
			return data[ans];
		}
		
		void print()
		{
			cout<<"Stack Top to Bottom:"<<endl;
			for(int i=top;i>=0;i--)
			{
				cout<<data[i]<<endl;
			}
		}
};

int main()
{
	Stack s1(5);
	s1.push(1);
	cout<<s1.topE()<<endl;
	s1.push(2);
	s1.push(3);
	cout<<s1.topE()<<endl;
	s1.push(4);
	s1.push(5);
	cout<<s1.topE()<<endl;
	
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
