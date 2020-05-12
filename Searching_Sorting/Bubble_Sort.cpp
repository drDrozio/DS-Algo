#include<iostream>

using namespace std;

int* bubble_sort(int*a,int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
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
	a=bubble_sort(a,n);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
}
