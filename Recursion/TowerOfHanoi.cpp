#include<iostream>

using namespace std;

void toh(int n,char source,char dest,char via)
{
	if(n==1)
	{
		cout<<source<<"->"<<dest<<endl;
		return;
	}
	toh(n-1,source,via,dest);
	cout<<source<<"->"<<dest<<endl;
	toh(n-1,via,dest,source);	
	return;
}

int main()
{
	cout<<"Tower of Hanoi "<<endl;
	int num;
	char source='x';
	char dest='y';
	char med='z';
	cout<<"Enter number of discs : ";
	cin>>num;
	cout<<"Sequence for moving top disc :-"<<endl;
	toh(num,source,dest,med);
}
