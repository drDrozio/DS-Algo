#include<iostream>
using namespace std;

void printSeq(int* n,int t)
{
	for(int count=0;count<t;count++)
	{
		int num=n[count];
		for(int i=0;i<num;i++) //Number of rows
		{
			for(int j=num;j>0;j--)
			{
				for(int k=1;k<=num-i;k++)
					cout<<j<<" ";
			}
			cout<<"$";
		}
		cout<<endl;
	}
}

int main()
{
	int t;
	cin>>t;
	int* n=new int[t];
	int i=0;
	while(i<t)
	{
		cin>>n[i];
		i++;
	}
	
	printSeq(n,t);
}
