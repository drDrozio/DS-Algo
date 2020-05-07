#include<iostream>
using namespace std;

int minCostPathBruteHelper(int**mat,int m,int n,int i,int j)
{
	if(i==m-1 and j==n-1)
		return mat[i][j];
	if(i>=m || j>=n)
		return INT_MAX;
		
	int right=minCostPathBruteHelper(mat,m,n,i,j+1);
	int down=minCostPathBruteHelper(mat,m,n,i+1,j);
	int diagonal=minCostPathBruteHelper(mat,m,n,i+1,j+1);
	
	int minimum=min(min(right,down),diagonal);
	return minimum + mat[i][j];
}

int minCostPathBrute(int**mat,int m,int n)
{
	int i=0;
	int j=0;
	return minCostPathBruteHelper(mat,m,n,i,j);
}

int minCostPathMemoHelper(int**mat,int m,int n,int i,int j,int**output)
{
	if(i==m-1 and j==n-1)
		return mat[i][j];
	if(i>=m || j>=n)
		return INT_MAX;
		
	if(output[i][j]!=-1)	
		return output[i][j];
		
	int right=minCostPathMemoHelper(mat,m,n,i,j+1,output);
	int down=minCostPathMemoHelper(mat,m,n,i+1,j,output);
	int diagonal=minCostPathMemoHelper(mat,m,n,i+1,j+1,output);
	int minimum=min(min(right,down),diagonal);
	output[i][j]=minimum + mat[i][j];
	
	return output[i][j];
}

int minCostPathMemo(int**mat,int m,int n)
{
	int**output=new int*[m];
	for(int i=0;i<m;i++)
	{
		output[i]=new int[n];
	}
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			output[i][j]=-1;
	return minCostPathMemoHelper(mat,m,n,0,0,output);
}

int minCostPathDP(int**mat,int m,int n)
{
	int**output=new int*[m];
	for(int i=0;i<m;i++)
	{
		output[i]=new int[n];
	}
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			output[i][j]=-1;
				
	output[0][0]=mat[0][0];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==0 && j==0)
				continue;
				
			int top=INT_MAX;
			int left=INT_MAX;
			int diag=INT_MAX;	
			
			if(i>=1)
				top=output[i-1][j];
			if(j>=1)
				left=output[i][j-1];
			if(i>=1 && j>=1)
				diag=output[i-1][j-1];
				
			int minimum=min(min(top,left),diag);
			output[i][j]=minimum+mat[i][j];
		}
	}
	return output[m-1][n-1];
}

int main()
{
	int m,n;
	cout<<"Enter number of rows of matrix : ";
	cin>>m;
	cout<<"Enter number of coulumns of matrix : ";
	cin>>n;
	
	//Creating Matrix
	int** mat=new int*[m];
	for(int i=0;i<m;i++)
		mat[i]=new int[n];
		
	cout<<"Enter matrix : "<<endl;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>mat[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
	
	cout<<"Min Cost Path (Brute Force) = "<<minCostPathBrute(mat,m,n)<<endl;
	cout<<"Min Cost Path (Memoization) = "<<minCostPathMemo(mat,m,n)<<endl;
	cout<<"Min Cost Path (DP) = "<<minCostPathDP(mat,m,n)<<endl;
}
