#include<iostream>
#include<algorithm>

using namespace std;

int lis(int* a,int n)
{
	if(n<=1)
		return 1;
		
	int inc=1+lis(a+1,n-1);
	int exc=lis(a+1,n-1);
	int ans=max(inc,exc);
	
	if(a[0]<a[1])
		return 1+ans;
	else
		return ans;
}

int lisDP(int* a,int n)
{
	int* output=new int[n];
	for(int i=0;i<n;i++)
		output[i]=0;
	output[0]=1;
	for(int i=1;i<n;i++)
	{
		output[i]=1;
		int max=output[i];
		for(int j=i-1;j>=0;j--)
		{
			if(a[j]<=a[i])
			{
				if(max<output[j])
					max=a[j];
			}
			else
				continue;
		}
		output[i]=max+1;
	}
	int ans=output[0];
	for(int i=1;i<n;i++)
	{
		if(output[i]>ans)
		{
			ans=output[i];
		}
		else
			continue;
	}
	delete [] output;
	return ans;
}

int main()
{
	//7   9 1 2 5 3 0 8
	int n;
	int* arr=new int[n];
	cout<<"Enter number of elements in array : ";
	cin>>n;
	cout<<"Enter elements of the array : ";
	for(int i=0;i<n;i++)
		cin>>arr[i];
		
	cout<<"Length of longest increasing subsequence (Recursion)= "<<lis(arr,n)<<endl;
	cout<<"Length of longest increasing subsequence (DP)= "<<lisDP(arr,n)<<endl;
	
	delete [] arr;
}
