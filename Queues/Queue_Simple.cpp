#include<iostream>
using namespace std;

class Queue
{
	int* queue;
	int frontI;
	int rearI;
	int capacity;
	public:
		Queue(int s)
		{
			capacity=s;
			frontI=0;
			rearI=0;
			queue=new int[capacity];
		}
		
		bool isEmpty()
		{
			if(frontI==rearI)
				return true;
		}
		
		bool isFull()
		{
			if(rearI==capacity)
				return true;
		}
		
		void enqueue(int element)
		{
			if(isFull())
			{
				cout<<"Queue is Full/Overflow.";
				return;
			}
			queue[rearI]=element;
			rearI++;
		}
		
		int front()
		{
			if(isEmpty())
			{
				cout<<"Queue is Empty/Underflow.";
				return 6969;
			}
			return queue[frontI];
		}
		
		int dequeue()
		{
			if(isEmpty())
			{
				cout<<"Queue is Empty/Underflow.";
				return 6969;
			}
			int temp=queue[frontI];
			for(int i=frontI+1;i<=rearI;i++)
			{
				queue[i]=queue[i+1];
			}
			rearI--;
			return temp;
		}
		
		void print()
		{
			for(int i=frontI;i<=rearI;i++)
			{
				cout<<queue[i]<<endl;
			}
		}
};


int main()
{
	Queue q1(5);
	q1.enqueue(10);
	q1.enqueue(20);
	q1.enqueue(30);
	q1.enqueue(40);
	q1.enqueue(50);
	q1.print();
	q1.dequeue();
}
