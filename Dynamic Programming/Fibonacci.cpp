#include<iostream>
#include<ctime>

using namespace std;

double fibo1(int n)
{
	if(n<=1)
		return n;
	
	return fibo1(n-1)+fibo1(n-2);
}

double fibo2Helper(int n,int ans[])
{
	if(n<=1)
		return n;
		
	if(ans[n]!=-1)
		return ans[n];
	else
	{
		ans[n]=fibo2Helper(n-1,ans)+fibo2Helper(n-2,ans);
		return ans[n];
	}
}

double fibo2(int n)
{
	int* ans=new int[n+1];
	for(int i=0;i<n+1;i++)
		ans[i]=-1;
	return fibo2Helper(n,ans);
}

double fibo3(int n)
{
	int* ans=new int[n+1];
	
	ans[0]=0;
	ans[1]=1;
	
	for(int i=2;i<n+1;i++)
		ans[i]=ans[i-1]+ans[i-2];
	
	return ans[n];
}

int main()
{
	int n;
	cout<<"Enter number n : ";
	cin>>n;
	/*
	cout<<"Brute Force solution : "<<endl;
	clock_t begin1, end1;
	double time1;
	begin1 = clock();
	double ans1=fibo1(n);
	end1 = clock();
	cout<<n<<"th Fibonacci number = "<<ans1<<endl;
	time1 = (double)(end1 - begin1) / CLOCKS_PER_SEC;
	cout <<"Time of Execution = "<<time1<<endl;
	cout<<endl;
	*/
	cout<<"Memoization solution : "<<endl;
	clock_t begin2, end2;
	double time2;
	begin2 = clock();
	double ans2=fibo2(n);
	end2 = clock();
	cout<<n<<"th Fibonacci number = "<<ans2<<endl;
	time2 = (double)(end2 - begin2) / CLOCKS_PER_SEC;
	cout <<"Time of Execution = "<<time2<<endl;
	cout<<endl;
	cout<<"Dynamic Programming solution : "<<endl;
	clock_t begin3, end3;
	double time3;
	begin3 = clock();
	double ans3=fibo3(n);
	end3 = clock();
	cout<<n<<"th Fibonacci number = "<<ans3<<endl;
	time3 = (double)(end3 - begin3) / CLOCKS_PER_SEC;
	cout <<"Time of Execution = "<<time3<<endl;
	
}
