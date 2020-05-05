#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
using namespace std;

int** createGraph(int e,int v)
{
	int**edges=new int*[v];
	for(int i=0;i<v;i++)
	{
		edges[i]=new int[v];
		for(int j=0;j<v;j++)
			edges[i][j]=0;
	}
	for(int i=0;i<e;i++)
	{
		int f,s;
		cout<<"Enter vertices of edges : ";
		cin>>f>>s;
		edges[f][s]=1;
		edges[s][f]=1;
	}
	return edges;
}

void printDFS(int** edges,bool* visited,int v,int sv)
{
	cout<<sv<<" ";
	visited[sv]=true;
	for(int i=0;i<v;i++)
	{
		if(i==sv)
			continue;
		if(edges[sv][i]==1 && visited[i]==false)
		{
			printDFS(edges,visited,v,i);
		}
	}
	for(int i=sv;i<v;i++)
	{
		if(!visited[i])
			printDFS(edges,visited,v,i);	
	}
}

void printBFS(int**edges,bool*visited,int v,int sv)
{
	queue<int> q;
	q.push(sv);
	visited[sv]=true;
	while(q.size()!=0)
	{
		int front=q.front();
		cout<<front<<" ";
		q.pop();
		for(int i=0;i<v;i++)
		{
			if(edges[front][i]==1 && visited[i]==false)
			{
				q.push(i);
				visited[i]=true;
			}
			else
				continue;
		}
	}
	for(int i=0;i<v;i++)
	{
		if(!visited[i])
			printBFS(edges,visited,v,i);	
	}
}


void DFS(int**edges,int v)
{
	bool* visited1=new bool[v];
	for(int i=0;i<v;i++)
		visited1[i]=false;
		
	cout<<"Enter starting vertex : ";
	int sv;
	cin>>sv;
	printDFS(edges,visited1,v,sv);
	delete [] visited1;
}

void BFS(int**edges,int v)
{
	bool* visited2=new bool[v];
	for(int i=0;i<v;i++)
		visited2[i]=false;
		
	cout<<"Enter starting vertex : ";
	int sv;
	cin>>sv;
	printBFS(edges,visited2,v,sv);
	delete [] visited2;
}

bool hasPath(int start,int end,int v,int**edges,bool*visited)
{
	visited[start]=true;
	if(edges[start][end]==1)
		return true;
		
	for(int i=0;i<v;i++)
	{
		if(i==start)
			continue;
		if(edges[start][i]==1 && visited[i]==false)
		{
			return hasPath(i,end,v,edges,visited);
		}
	}
	return false;
}

bool hasPath(int start,int end,int v,int**edges)
{
	bool* visited=new bool[v];
	for(int i=0;i<v;i++)
		visited[i]=false;
		
	return hasPath(start,end,v,edges,visited);
}



vector<int>* getPathDFS(int**edges,int v,int start,int end,bool*visited)
{
	if(edges[start][end]==1)
	{
		vector<int>* ans=new vector<int>();
		ans->push_back(end);
		return ans;
	}
	
	visited[start]=true;	
	for(int i=0;i<v;i++)
	{
		if(edges[start][i]==1 && visited[i]==false)
		{
			visited[i]=true;
			vector<int>* output=getPathDFS(edges,v,i,end,visited);
			if(output!=NULL)
			{
				output->push_back(i);
			}
			return output;
		}
	}
	return NULL;
}

vector<int>* getPathDFS(int**edges,int v,int start,int end)
{
	bool* visited=new bool[v];
	for(int i=0;i<v;i++)
		visited[i]=false;
	vector<int>* op=getPathDFS(edges,v,start,end,visited);
	delete [] visited;
	return op;
}

vector<int>* getPathBFS(int**edges,int v,int start,int end)
{
	bool* visited=new bool[v];
	for(int i=0;i<v;i++)
		visited[i]=false;
		
	unordered_map<int,int> Map;
	
	queue<int> q;
	q.push(start);
	visited[start]=true;
	while(q.size()!=0 && q.front()!=end)
	{
		int front=q.front();
		cout<<front<<" ";
		q.pop();
		for(int i=0;i<v;i++)
		{
			if(edges[front][i]==1 && visited[i]==false)
			{
				q.push(i);
				visited[i]=true;
				Map[i]=front;
			}
			else
				continue;
		}
	}
	vector<int>*output=new vector<int>();
	int i=end;
	//output->pushback(end);
	while(i!=start)
	{
		output->push_back(i);
		i=Map[i];
	}
	output->push_back(start);
	return output;
}

vector<int>* traverseComp(bool* &visitedList,int sv,int**edges,int v)
{
	visitedList[sv]=true;
	for(int i=0;i<v;i++)
	{
		if(i==sv)
			continue;
		if(edges[sv][i]==1 && visitedList[i]==false)
		{
			vector<int>*ans=traverseComp(visitedList,i,edges,v);
			if(ans!=NULL)
				ans->push_back(i);
			return ans;
		}
	}
	return NULL;
}


int main()
{
	int v,e;
	cout<<"Enter number of vertices : ";
	cin>>v;
	cout<<"Enter number of edges : ";
	cin>>e;
	int** edges=createGraph(e,v);
	
	//Depth First Search Traversal
	cout<<"DFS : ";
	DFS(edges,v);
	cout<<endl;
	//Breath First Search Traversal
	cout<<"BFS : ";
	BFS(edges,v);
	cout<<endl;
	
	cout<<"Has Path?"<<endl;
	int start,end;
	cout<<"Enter starting vertex : ";
	cin>>start;
	cout<<"Enter ending vertex : ";
	cin>>end;
	if(hasPath(start,end,v,edges))
		cout<<"Path exists."<<endl;
	else
		cout<<"Path doesn't exist."<<endl;
	
	cout<<"Get Path->"<<endl;
	int start1,end1;
	cout<<"Enter starting vertex : ";
	cin>>start1;
	cout<<"Enter ending vertex : ";
	cin>>end1;
	cout<<"Path using DFS :-"<<endl;
	vector<int>* pathDFS=getPathDFS(edges,v,start1,end1);
	for(int i=0;i<pathDFS->size();i++)
	{
		cout<<pathDFS->at(i)<<" ";
	}
	cout<<endl;

	cout<<"Path using BFS :-"<<endl;
	vector<int>* pathBFS=getPathBFS(edges,v,start1,end1);
	for(int i=0;i<pathBFS->size();i++)
	{
		cout<<pathBFS->at(i)<<" ";
	}
	cout<<endl;
	
}
