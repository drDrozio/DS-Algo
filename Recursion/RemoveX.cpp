#include<iostream>

using namespace std;

void removeXRec(char a[],int size)
{
	if(size==0)
		return;
		
	if(a[0]=='x')
	{
		for(int i=0;i<size;i++)
			a[i]=a[i+1];
		removeXRec(a,size-1);
	}
	else
		removeXRec(a+1,size-1);
}

void removeX(char a[])
{
	int i=0;
	while(a[i]!='\0')
	{
		i++;
	}
	removeXRec(a,i);
}

int main()
{
	char a[1000];
	cout<<"Enter a string : ";
	cin>>a;
	removeX(a);
	cout<<a;
}
