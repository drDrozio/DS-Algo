#include<iostream>

using namespace std;

int* shell_sort(int*a,int n)
{
	int gap=n/2;
	while(gap>=1)
	{
		for(int i=0;i<n-gap;i++)
		{
			for(int j=i;j<n-gap;j=j+gap)
			{
				if(a[j]>=a[j+gap])
				{
					int temp=a[j];
					a[j]=a[j+gap];
					a[j+gap]=temp;
				}
			}
			
		}
		gap=gap/2;
	}
	return a;
}

int main()
{
	//10 77 62 14 9 30 21 80 25 70 55
	int n;
	cout<<"Enter size of array : ";
	cin>>n;
	int* a=new int[n];
	cout<<"Enter the "<<n<<" elements of the array : "<<endl;
	for(int i=0;i<n;i++)
		cin>>a[i];
	a=shell_sort(a,n);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
}
