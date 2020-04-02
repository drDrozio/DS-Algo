#include<iostream>
#include<cstring>
#include<string>

using namespace std;

bool checkPalindrome(string str)
{
	//Finding length
	int i=0;
	while(str[i]!='\0')
	{
		i++;
	}
	int end=i-1;
	int start=0;
	
	while(start<=end)
	{
		if(str[start]!=str[end])
			return false;
		start++;
		end--;
	}
	return true;
}


string deleteSpaces(string str)
{
	int length=str.length();
	int end=length-1;
	int i=end;
	int countSpace=0;
	while(i!=-1)
	{
		if(str[i]==' ')
		{
			countSpace++;
			for(int j=i;j<end;j++)
			{
				str[j]=str[j+1];
			}
		}
		i--;
	}
	str.resize(length-countSpace);
	
	return str;
}

string reverseString(string str)
{
	int length=str.length();
	int end=length-1;
	int start=0;
	
	while(start<end)
	{
		char temp=str[start];
		str[start]=str[end];
		str[end]=temp;
		start++;
		end--;
	}
	return str;
}

string reverseStringWordwise(string str)
{
	//Reverse string
	str=reverseString(str);	
	
	int i=0;
	string final;
	while()
	{
		string str1;
		int j=0;
		int s=0;
		while()
		{
			if(str[j]==' ')
			{
				str1=reverseString(str1);
			}
			else
			{
				str1[j]=str[j];
			}
		}
	}
}


int main()
{
	string str;
	cout<<"Enter string : ";
	getline(cin,str,'\n');
	cout<<str<<endl;
	int l=str.length();
	cout<<l<<endl;
	
	//Check Palindrome
	if(checkPalindrome(str))
		cout<<"String is a Palindrome.";
	else
		cout<<"String is not a Palindrome.";
		
	//Delete spaces between words
	string str1=deleteSpaces(str);
	cout<<endl<<str1;
	
	//Reverse string word wise
	//string str2=reverseStringWordwise(str);
	//cout<<endl<<str2;
		
}
