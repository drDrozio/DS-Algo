#include<iostream>
using namespace std;

double staircaseWays(int n)
{
	if(n>3)
	{
		double*ans=new double[n+1];
		
		ans[0]=1;
		ans[1]=1;
		ans[2]=2;
		ans[3]=4;
		
		for(int i=4;i<=n;i++)
		{
			ans[i]=ans[i-1]+ans[i-2]+ans[i-3];
		}
		return ans[n];
	}
	else
	{
		if(n==1)
			return 1;
		else
		{
			if(n==2)
				return 2;
			else
				return 4;
		}
	}
}

int main()
{
	int n;
	cout<<"Enter number of stairs : ";
	cin>>n;
	cout<<"Number of ways to climb "<<n<<" Staircases = "<<staircaseWays(n);
}
