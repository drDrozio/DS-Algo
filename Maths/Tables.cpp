#include<iostream>
using namespace std;

void printTables(int* ptr,int size)
{
	for (int s=0;s<size;s++)
	{
		int num=ptr[s];
		
		for(int i=1;i<=10;i++)
		{
			cout<<num*i<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	int t;
	cin>>t;
	
	int* ptr=new int[t];
	for(int i=0;i<t;i++)
	{
		cin>>ptr[i];
		
	}
	
	printTables(ptr,t);
}
