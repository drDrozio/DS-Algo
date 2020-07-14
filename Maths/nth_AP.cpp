#include<iostream>
using namespace std;

void APnthTerm(int* ptr,int size)
{
	for (int s=0;s<size;s=s+3)
	{
		int num1=ptr[s];
		int num2=ptr[s+1];
		int n=ptr[s+2];
		
		int d=num2-num1;
		cout<<num1+(n-1)*d;
		
		cout<<endl;
	}
}

int main()
{
	int t;
	cin>>t;
	
	int* ptr=new int[t*3];
	for(int i=0;i<t*3;i=i+3)
	{
		cin>>ptr[i]>>ptr[i+1];
		cin>>ptr[i+2];
	}
		
	APnthTerm(ptr,t*3);
}
