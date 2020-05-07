#include<iostream>
#include<string>
using namespace std;

int editDistanceBrute(string s,string t)
{
	//Base Case
	if(t.size()==0 || t.size()==0)
		return max(t.size(),t.size());
	
	if(s[0]==t[0])
		return editDistanceBrute(s.substr(1),t.substr(1));
		
	int ins=editDistanceBrute(s.substr(1),t);
	int del=editDistanceBrute(s,t.substr(1));
	int rep=editDistanceBrute(s.substr(1),t.substr(1));
	
	int minSteps=min(min(ins,del),rep);
	return 1+minSteps;
}

int main()
{
	string s,t;
	cout<<"Enter string 1 : ";
	cin>>s;
	cout<<"Enter string 2 : ";
	cin>>t;
	
	cout<<"Edit Distance (Brute Force)= "<<editDistanceBrute(s,t)<<endl;
}
