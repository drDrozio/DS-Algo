#include<iostream>
using namespace std;

void countSquares(int* ptr,int size)
{
	for(int s=0;s<size;s++)
	{
		int num=ptr[s];
		int i=1;
		while(i*i<num)
			i++;
		cout<<i-1<<endl;
	}
}

int main()
{
	int t;
	cin>>t;
	
	int* ptr=new int[t];
	for(int i=0;i<t;i++)
		cin>>ptr[i];

	countSquares(ptr,t);
}
