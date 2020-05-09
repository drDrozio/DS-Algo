#include<iostream>

using namespace std;

void replacepiRec(char a[],int size)
{
	if(size==0 || size==1) 
		return;
	if(a[0]=='p' && a[1]=='i')
	{
		for(int i=size+1;i>=0;i--)
			a[i+2]=a[i];
		a[0]='3';
		a[1]='.';
		a[2]='1';
		a[3]='4';
		replacepiRec(a+4,size-2);
	}
	else
		replacepiRec(a+1,size-1);
}

void replacepi(char a[])
{
	int i=0;
	while(a[i]!='\0')
	{
		i++;
	}
	replacepiRec(a,i);
}

int main()
{
	char a[1000];
	cout<<"Enter a string : ";
	cin>>a;
	replacepi(a);
	cout<<a;
}
