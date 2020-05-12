#include<iostream>

using namespace std;

int* insertion_sort(int* a,int n)
{
	for(int i=1;i<n;i++)
	{
		int temp=a[i];
		int j=i-1;
		while(temp<a[j] && j>=0)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
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
	int*ptr=insertion_sort(a,n);
	for(int i=0;i<n;i++)
		cout<<ptr[i]<<" ";
}
