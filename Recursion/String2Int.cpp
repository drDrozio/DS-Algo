#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int str2intRec(char a[],int size)
{
	if(size==0)
		return 0;
		
	int b=a[0];
	b=b-48;
	b=b*pow(10,size-1);
	return b+str2intRec(a+1,size-1);
}

int str2int(char a[])
{
	int i=0;
	while(a[i]!='\0')
		i++;
	return str2intRec(a,i);
}

int main()
{
	char a[1000];
	cout<<"Enter a string : ";
	cin>>a;
	int num=str2int(a);
	cout<<"In integer = "<<num<<endl;
	cout<<"Testing integer property by dividing by 10 : "<<num/10;
}
