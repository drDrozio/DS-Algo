#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int allPossibleWaysRec(int a,int b,int limit,int start)
{
	if(a==0)
		return 1;
	if(a<0)
		return 0;
	int ways=0;
	for(int i=start;i<=limit;i++)
	{
		ways=ways+allPossibleWaysRec((a-pow(i,b)),b,limit,i+1);
	}
	return ways;
}

int allPossibleWays(int a,int b)
{
	int num=a;
	int i=2;
	bool flag;
	while(num<=a)
	{
		num=pow(i,b);
		i++;
		if(num==a)
			flag=true;
	}
	int limit=i-1;
	int start=1;
	if(flag==true)
		return 1+allPossibleWaysRec(a,b,limit,start);
	else
		return allPossibleWaysRec(a,b,limit,start);
}

int main()
{
	int a,b;
	cout<<"Enter a and b : ";
	cin>>a>>b;
	
	cout<<allPossibleWays(a,b);
}
