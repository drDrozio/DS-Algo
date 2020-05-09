#include<iostream>

using namespace std;

void pairStarRec(char a[],int size)
{
	if(size==0)
		return;
		
	if(a[0]==a[1])
	{
		for(int i=size;i>1;i--)
			a[i]=a[i-1];
		a[1]='*';
		pairStarRec(a+2,size-1);
	}
	else
		pairStarRec(a+1,size-1);
}

void pairStar(char a[])
{
	int i=0;
	while(a[i]!='\0')
		i++;
	pairStarRec(a,i);
}

int main()
{
	char a[1000];
	cout<<"Enter a string : ";
	cin>>a;
	pairStar(a);
	cout<<a;
}
