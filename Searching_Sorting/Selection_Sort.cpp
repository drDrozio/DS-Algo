#include<iostream>

using namespace std;

int* selection_sort(int*a,int n)
{
	for(int i=0;i<n-1;i++)
	{
		int minIndex=i;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<a[minIndex])
				minIndex=j;
		}
		int temp=a[minIndex];
		a[minIndex]=a[i];
		a[i]=temp;
	}
	return a;
}

int main()
{
	int n;
	cout<<"Enter size of array : ";
	cin>>n;
	int* a=new int[n];
	cout<<"Enter the "<<n<<" elements of the array : "<<endl;
	for(int i=0;i<n;i++)
		cin>>a[i];
	a=selection_sort(a,n);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
}
