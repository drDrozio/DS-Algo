#include<iostream>
#include<algorithm>

using namespace std;

class Edge
{
	public:
		int v1;
		int v2;
		int weight;
};

Edge* takeInput(int v,int e)
{
	Edge* graph=new Edge[e];
	int i=0;
	while(i<e)
	{
		cout<<"Enter source vertex : ";
		cin>>graph[i].v1;
		cout<<"Enter destination vertex : ";
		cin>>graph[i].v2;
		cout<<"Enter weight of edge : ";
		cin>>graph[i].weight;
		i++;
	}
	return graph;
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

bool sortByWeight(Edge i,Edge j)
{
	return i.weight<j.weight;
}

Edge* kruskals(Edge*graph,int e,int v)
{
	Edge* MST=new Edge[v-1];
	int* parent=new int[v];
	for(int i=0;i<v;i++)
		parent[i]=i;
	
	int count=0;
	int i=0;
	while(count<v-1)
	{
		int w=graph[i].weight;
		int v1=graph[i].v1;
		int v2=graph[i].v2;
		int p1=parent[v1];
		int p2=parent[v2];
		
		while(p1!=parent[p1])
			p1=parent[p1];
		while(p2!=parent[p2])
			p2=parent[p2];
			
		if(p1!=p2)
		{
			MST[count].v1=v1;
			MST[count].v2=v2;
			MST[count].weight=w;
			count++;
			i++;
			parent[v2]=p1;
		}
		else
		{
			i++;
		}
	}
	return MST;
}

int main()
{
	//6 11 0 1 1 0 2 5 2 3 10 0 3 4 1 3 3 1 2 6 3 4 7 2 4 8 4 5 2 2 5 9 3 5 6
	int v;
	int e;
	cout<<"Enter number of Vertices : ";
	cin>>v;
	cout<<"Enter number of Edges : ";
	cin>>e;
	Edge* graph=takeInput(v,e);
	cout<<endl;
	printGraph(graph,e);
	cout<<endl;
	sort(graph,graph+e,sortByWeight);
	printGraph(graph,e);
	cout<<endl;
	Edge* MST=kruskals(graph,e,v);
	cout<<"Minimum Spanning Tree using Kruskal's Algo:"<<endl;
	printGraph(MST,v-1);
	
}
