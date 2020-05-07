#include<iostream>
#include<cstring>
using namespace std;

int lcsBrute(string s,string t)
{
	if(s.size()==0 || t.size()==0)
		return 0;
		
	if(s[0]==t[0])
		return 1+lcsBrute(s.substr(1),t.substr(1));	
	else
	{
		int a=lcsBrute(s.substr(1),t);
		int b=lcsBrute(s,t.substr(1));	
		return max(a,b);
	}	
}

int lcsMemoHelper(string s,string t,int**output)
{
	int m=s.size();
	int n=t.size();
	
	if(s.size()==0 || t.size()==0)
		return 0;
		
	if(output[m][n]!=-1)
		return output[m][n];
	
	int ans;
	if(s[0]==t[0])
		ans= 1+lcsBrute(s.substr(1),t.substr(1));	
	else
	{
		int a=lcsBrute(s.substr(1),t);
		int b=lcsBrute(s,t.substr(1));	
		ans= max(a,b);
	}
	output[m][n]=ans;
	return ans;
}

int lcsMemo(string s,string t)
{
	int m=s.size();
	int n=t.size();
	int** output=new int*[m+1];
	for(int i=0;i<=m;i++)
		output[i]=new int[n+1];
		
	for(int i=0;i<=m;i++)
		for(int j=0;j<=n;j++)
			output[i][j]=-1;
			
	return lcsMemoHelper(s,t,output);
}

int lcsDP(string s,string t)
{
	int m=s.size();
	int n=t.size();
	int** output=new int*[m+1];
	for(int i=0;i<=m;i++)
		output[i]=new int[n+1];
		
	for(int i=0;i<=m;i++)
		output[0][i]=0;
	for(int i=0;i<=m;i++)
		output[i][0]=0;
	
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(s[m-i]==t[n-j])
				output[i][j]=1+output[i-1][j-1];
			else
			{
				int a=output[i-1][j];
				int b=output[i][j-1];
				int c=output[i-1][j-1];
				output[i][j]=max(max(a,b),c);
			}
		}
	}
	return output[m][n];
}

int main()
{
	string s;
	string t;
	cout<<"Enter first string : ";
	cin>>s;
	cout<<"Enter second string : ";
	cin>>t;
	
	cout<<"Longest Common Subsequence (Brute Force)= "<<lcsBrute(s,t)<<endl;
	cout<<"Longest Common Subsequence (Memoization)= "<<lcsMemo(s,t)<<endl;
	cout<<"Longest Common Subsequence (DP)= "<<lcsDP(s,t)<<endl;
	
}
