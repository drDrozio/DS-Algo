#include<iostream>
#include<bits/stdc++.h> 

using namespace std;

int minCountBrute(int n)
{
	if(n==0)
		return 0;
	
	int minimum=INT_MAX;	
	for(int i=1;i*i<=n;i++)
	{
		int temp=minCountBrute(n-(i*i));
		if(temp<minimum)
		{
			minimum=temp;
		}
	}
	return 1+minimum;
}

int minCountMemoHelper(int ans[],int n)
{
	if(n==0)
		return 0;
		
	if(ans[n]!=-1)
		return ans[n];
	else
	{
		int minimum=INT_MAX;	
		for(int i=1;i*i<=n;i++)
		{
			int temp=minCountMemoHelper(ans,n-(i*i));
			if(temp<minimum)
			{
				minimum=temp;
			}
		}
		ans[n]=1+minimum;
		return ans[n];
	}
}

int minCountMemo(int n)
{
	int* ans=new int[n+1];
	for(int i=0;i<=n;i++)
		ans[i]=-1;
	return minCountMemoHelper(ans,n);
}

int minCountDP(int n)
{
	int* ans=new int[n+1];
	for(int i=0;i<=n;i++)
		ans[i]=0;
		
	ans[0]=0;
	ans[1]=1;
	
	for(int i=2;i<=n;i++)
	{
		int minimum=INT_MAX;
		for(int j=1;j*j<=n;j++)
		{
			int temp=ans[i-j*j];
			if(temp<=minimum)
				minimum=temp;
		}
		ans[i]=1+minimum;
	}
	return ans[n];
}


int main()
{
	cout<<"Enter number : ";
	int n;
	cin>>n;
	cout<<"Minimum count (Brute Force)= "<<minCountBrute(n)<<endl;
	cout<<"Minimum count (Memoization)= "<<minCountMemo(n)<<endl;
	cout<<"Minimum count (DP)= "<<minCountDP(n)<<endl;
}
