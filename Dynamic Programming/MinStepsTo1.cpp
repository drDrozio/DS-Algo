#include<iostream>
#include<algorithm>
#include<bits/stdc++.h> 
using namespace std;

int minSteps1(int n)
{
	if(n<=1)
		return 0;
		
	int x=INT_MAX;
	int y=INT_MAX;
	int z=minSteps1(n-1);
	if(n%3==0)
		x=minSteps1(n/3);
	if(n%2==0)
		y=minSteps1(n/2);
		
	int minimum=min(min(x,y),z);
	return 1+minimum;
}

int minStepsDP(int n)
{
	int* ans=new int[n+1];
	ans[0]=0;
	ans[1]=1;
	ans[2]=1;
	ans[3]=1;
	
	for(int i=4;i<=n;i++)
	{
		int x=INT_MAX;
		int y=INT_MAX;
		int z=ans[i-1];
		if(i%3==0)
			x=ans[i/3];
		if(i%2==0)
			y=ans[i/2];
			
		ans[i]=1+min(min(x,y),z);
	}
	return ans[n];
}

int minStepsMemoHelper(int n,int ans[])
{
	if(n<=1)
		return 0;
	if(ans[n]!=-1)
		return ans[n];
	else
	{
		int x=INT_MAX;
		int y=INT_MAX;
		int z=minStepsMemoHelper(n-1,ans);
		if(n%3==0)
			x=minStepsMemoHelper(n/3,ans);
		if(n%2==0)
			y=minStepsMemoHelper(n/2,ans);
		
		int minimum=min(min(x,y),z);
		ans[n]=1+minimum;
		return ans[n];
	}
}

int minStepsMemo(int n)
{
	int* ans=new int[n+1];
	for(int i=0;i<n+1;i++)
		ans[i]=-1;
	return minStepsMemoHelper(n,ans);
}

int main()
{
	cout<<"Enter number n : ";
	int n;
	cin>>n;
	
	//Brute force solution
	cout<<"Brute Force Solution-"<<endl;
	int min1=minSteps1(n);
	cout<<min1<<" number of steps required."<<endl;
	cout<<endl;
	
	//DP solution
	cout<<"DP Solution-"<<endl;
	int minDP=minStepsDP(n);
	cout<<minDP<<" number of steps required."<<endl;
	cout<<endl;
	
	//Memoization solution
	cout<<"Memoization Solution-"<<endl;
	int minMemo=minStepsMemo(n);
	cout<<minMemo<<" number of steps required."<<endl;
}
