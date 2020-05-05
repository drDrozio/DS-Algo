#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Edge
{
	public:
		int v1;
		int v2;
		int weight;
};

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
		int f,s,w;
		cout<<"Enter vertices of edges : ";
		cin>>f>>s;
		cout<<"Enter weight : ";
		cin>>w;
		edges[f][s]=w;
		edges[s][f]=w;
	}
	return edges;
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

void printGraph(Edge* graph,int e)
{
	int i=0;
	while(i<e)
	{
		cout<<graph[i].v1<<"---"<<graph[i].v2<<" Weight="<<graph[i].weight<<endl;
		i++;
	}	
}

int findMinVertex(int* weight,int v,bool* visited)
{
	int minWeight=INT_MAX;
	int minIndex=-1;
	for(int i=0;i<v;i++)
	{
		if(minWeight>=weight[i] && visited[i]==false)
		{
			minWeight=weight[i];
			minIndex=i;
		}
	}
	return minIndex;
}

Edge* prims(int**edges,int v)
{
	int* parent=new int[v];
	int* weight=new int[v];
	bool* visited=new bool[v];
	
	for(int i=0;i<v;i++)
	{
		visited[i]=false;
		parent[i]=-1;
		weight[i]=INT_MAX;
	}
	parent[0]=-1;
	weight[0]=0;
	int count=0;
	while(count<v-1)
	{
		int currentVertex=findMinVertex(weight,v,visited);
		visited[currentVertex]=true;
		for(int i=0;i<v;i++)
		{
			if(edges[currentVertex][i]!=0 && visited[i]==false)
			{
				if(edges[currentVertex][i]<weight[i])
				{
					weight[i]=edges[currentVertex][i];
					parent[i]=currentVertex;
				}
			}
		}
		count++;
	}
	for(int i=0;i<v;i++)
	{
		if(parent[i]!=-1)
			cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
	}
	
	Edge* MST=new Edge[v-1];
	int index=0;
	for(int i=0;i<v;i++)
	{
		if(parent[i]!=-1)
		{
			MST[index].v1=parent[i];
			MST[index].v2=i;
			MST[index].weight=edges[parent[i]][i];
			index++;
		}
	}
	return MST;
}

int main()
{
	//4 4 0 1 3 0 3 5 1 2 1 2 3 8
	int v,e;
	cout<<"Enter number of vertices : ";
	cin>>v;
	cout<<"Enter number of edges : ";
	cin>>e;
	int** edges=createGraph(e,v);
	cout<<endl;
	BFS(edges,v);
	cout<<endl;
	Edge* MST=prims(edges,v);
	printGraph(MST,v-1);
	cout<<endl;
}
