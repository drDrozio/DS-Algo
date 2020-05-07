#include<iostream>
#include<bits/stdc++.h> 

using namespace std;

double numBTreesBrute(int h)
{
	if(h<=1)
		return 1;
		
	double x=numBTreesBrute(h-1);
	double y=numBTreesBrute(h-2);
	
	double num=x*x+2*x*y;
	return num;
}

double numBTreesMemoH(double ans[],int h)
{
	if(h<=1)
		return 1;
		
	if(ans[h]!=-1)
		return ans[h];
	else
	{
		double x=numBTreesMemoH(ans,h-1);
		double y=numBTreesMemoH(ans,h-2);
	
		ans[h]=x*x+2*x*y;
		return ans[h];
	}
}

double numBTreesMemo(int h)
{
	double* ans=new double[h+1];
	for(int i=0;i<=h;i++)
		ans[i]=-1;
	return numBTreesMemoH(ans,h);
}

double numBTreesDP(int h)
{
	double* ans=new double[h+1];
	for(int i=0;i<=h;i++)
		ans[i]=0;
		
	ans[0]=1;
	ans[1]=1;
	
	for(int i=2;i<=h;i++)
	{
		ans[i]=2*ans[i-1]*ans[i-2]+ans[i-1]*ans[i-1];
	}
	return ans[h];
}

int main()
{
	cout<<"Enter height h : ";
	int h;
	cin>>h;
	cout<<"Number of Binary Trees with height h (Brute Force)= "<<numBTreesBrute(h)<<endl;
	cout<<"Number of Binary Trees with height h (Memoization)= "<<numBTreesMemo(h)<<endl;
	cout<<"Number of Binary Trees with height h (DP)= "<<numBTreesDP(h)<<endl;
}
