#include<iostream>

using namespace std;

int loot(int* money,int n)
{
	if(n<=0)
		return 0;
		
	int inc=money[0]+loot(money+2,n-2);
	int exc=loot(money+1,n-1);
	return max(inc,exc);
}

/*
int* lootMemo(int* money,int n,int* ans)
{
	
	
	return max(m[0]+)
}

int lootMemo(int*money,int n)
{
	int* ans=new int[n];
	
	ans[0]=money[0];
	ans[1]=max(money[1],ans[0]);
	
	lootMemo(money,n,ans);
}
*/

int lootDP(int* money,int n)
{
	int* ans=new int[n];
	ans[0]=money[0];
	ans[1]=max(money[1],ans[0]);
	for(int i=2;i<n;i++)
	{
		ans[i]=max((money[i]+ans[i-2]),ans[i-1]);
	}
	return ans[n-1];
}

int main()
{
	//6 5 5 10 100 10 5  ans=110
	int n;
	cout<<"Enter number of houses : ";
	cin>>n;
	int* money=new int[n];
	cout<<"Enter money in the houses : ";
	for(int i=0;i<n;i++)
		cin>>money[i];
	cout<<endl;
	
	cout<<"Maximum money looted (Brute Force) : "<<loot(money,n)<<endl;
	cout<<"Maximum money looted (DP) : "<<lootDP(money,n)<<endl;
	
}
