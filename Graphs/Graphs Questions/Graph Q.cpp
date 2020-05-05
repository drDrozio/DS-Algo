#include<iostream>
#include<vector>
#include<string>

using namespace std;

/*
int count=0;
void DFScount(int** adj,int n,bool*visited,int sv)
{
	visited[sv]=true;
	for(int i=0;i<=n;i++)
	{
		if(i==sv)
			continue;
		if(visited[i]==false && adj[sv][i]==1)
		{
			DFScount(adj,n,visited,i);
		}
	}
	count++;
	for(int i=0;i<=n;i++)
	{
		if(visited[i]==false)
			DFScount(adj,n,visited,i);
	}
}

int islands(int n,int m,vector<int>u,vector<int>v)
{
	//Creating Adjacency Matrix
	int** adj=new int*[n];
	for(int i=0;i<=n;i++)
		adj[i]=new int[n];
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			adj[i][j]=0;
		}
	}
	for(int i=0;i<=n;i++)
	{
		adj[i][u[i]]=1;
		adj[i][v[i]]=1;
	}
	//Creating Visited list
	bool* visited=new bool[n];
	for(int i=0;i<=n;i++)
		visited[i]=false;
	int sv;
	cout<<"Enter starting vertex : ";
	cin>>sv;
	DFS(adj,n,visited,sv);
	return count;
}
*/

bool hasPath(char** matrix,string s,int m,int n,int i,int j)
{
	if(s.size()==0)
		return true;
	
	if(i-1>=0)
	{
		if(j-1>=0)
		{
			if(matrix[i-1][j-1]==s[0])
			{
				visited[i-1][j-1]=true;
				return hasPath(matrix,s.substr(1),m,n,i-1,j-1);
			}
				
		}
		if(matrix[i-1][j]==s[0])
			return hasPath(matrix,s.substr(1),m,n,i,j-1);
		if(j+1<n)
		{
			if(matrix[i-1][j+1]==s[0])
				return hasPath(matrix,s.substr(1),m,n,i-1,j+1);
		}
	}
	if(i+1<m)
	{
		if(j-1>=0)
		{
			if(matrix[i+1][j-1]==s[0])
				return hasPath(matrix,s.substr(1),m,n,i+1,j-1);
		}
		if(matrix[i+1][j]==s[0])
			return hasPath(matrix,s.substr(1),m,n,i+1,j);
		if(j+1<n)
		{
			if(matrix[i+1][j+1]==s[0])
				return hasPath(matrix,s.substr(1),m,n,i+1,j+1);
		}
	}
	if(j-1>=0)
	{
		if(matrix[i][j-1]==s[0])
			return hasPath(matrix,s.substr(1),m,n,i,j-1);
	}
	if(j+1<n)
	{
		if(matrix[i][j+1]==s[0])
			return hasPath(matrix,s.substr(1),m,n,i,j+1);
	}
	return false;
}

bool checkMatrix(char** matrix,string s,int m,int n)
{
	int svrow=0;
	int svcol=0;
	bool**visited=new bool*[m];
	for(int i=0;i<m;i++)
		visited[i]=new bool[n];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
			visited[i][j]=false;
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(s[0]==matrix[i][j])
			{
				svrow=i;
				svcol=j;
				visited[i][j]=true;
				return hasPath(matrix,s.substr(1),m,n,svrow,svcol);
			}
		}
	}
	return false;
}

int main()
{
	//Check Matrix
	//C X D X N X N X N X A X O X I X G X I X J X
	int m,n;
	cout<<"Enter number of rows : ";
	cin>>m;
	cout<<"Enter number of columns : ";
	cin>>n;
	
	char** matrixWord=new char*[m];
	for(int i=0;i<m;i++)
		matrixWord[i]=new char[n];
	
	cout<<"Enter matrix characterwise. (Rows then Columns) : "<<endl;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
			cin>>matrixWord[i][j];
	}
	cout<<endl;
	string s;
	cout<<"Enter string to be searched for : ";
	cin>>s;
	if(checkMatrix(matrixWord,s,m,n))
		cout<<"String is present."<<endl;
	else
		cout<<"String is not present."<<endl;
}
