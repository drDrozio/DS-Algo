#include<iostream>
using namespace std;

int countDigits(int num)
{
	if(num<10)
		return 1;
		
	num=num/10;
	return countDigits(num)+1;
}

double power(int x,int n)
{
	if(n==0)
		return 1;
		
	return x*power(x,n-1);
}

int printnum(int n)
{
	if(n==1)
	{
		cout<<1<<" ";
		return 1;
	}
	
	cout<<1+printnum(n-1)<<" ";
}

bool isSorted(int a[],int size)
{
	if(size==0 || size==1)
		return true;
	if(a[0]>a[1])
		return false;
		
	return isSorted(a+1,size-1);
}

int main()
{
	/*
	cout<<"Count digits recursively--- "<<endl;
	int num;
	cout<<"Enter number : ";
	cin>>num;
	cout<<"Number of Digits = "<<countDigits(num)<<endl;
	
	cout<<"Power of x--- "<<endl;
	int x;
	cout<<"Enter x : ";
	cin>>x;
	int n;
	cout<<"Enter n : ";
	cin>>n;
	cout<<"x power n = "<<power(x,n)<<endl;
	
	cout<<"Print numbers 1 to n--- "<<endl;
	int n1;
	cout<<"Enter number : ";
	cin>>n1;
	cout<<"Ascending order = ";
	printnum(n1);
	cout<<endl;
	*/
	
	cout<<"Check if array is sorted"<<endl;
	int n2;
	cout<<"Enter size of array : ";
	cin>>n2;
	int a[n2];
	cout<<endl<<"Enter elements of array";
	for(int i=0;i<n2;i++)
	{
		cin>>a[i];
	}
	if(isSorted(a,n2))
	{
		cout<<endl<<"Array is sorted";
	}
	else
	{
		cout<<endl<<"Array is not sorted";
	}
	cout<<endl;
	
	
}
