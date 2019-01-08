#include<iostream>
#include<stack>
#include<queue>
#include "header/priorityQueue.h"

using namespace std;

struct Graph
{
int V;
int E;
int **adj;
};

template<typename T>
class GraphAlgo
{
	public:
	struct Graph *create();
	void show(struct Graph *G);
	void DFS(struct Graph *G);
	void BFS(struct Graph *G);
	static int *getIndegree(struct Graph *G)
	{
		int *indegree=(int *)malloc(sizeof(G->V)*sizeof(int *));
		for(int i=0;i<G->V;i++)
		indegree[i]=0;

		for(int i=0;i<G->V;i++)
		{
			int count=0;
			for(int j=0;j<G->V;j++)
			{	
				if(G->adj[j][i]==1)
				count++;
			}
			indegree[i]=count;
		}

		return indegree;
	}
	void topologicalSort(struct Graph *G);
	void unweightedSortedPath(struct Graph *G,int s,int d);
	void dijkstraSortedPath(struct Graph *G);
};


template<typename T>
struct Graph *GraphAlgo<T>::create()
{
int v,u,w;
struct Graph *G=(struct Graph *)malloc(sizeof(struct Graph));
	if(!G)
	{
		cout<<endl<<"Memory Error"<<endl;
		return NULL;
	}
	else
	{
		cout<<endl<<"Enter how many vertices and edges: "<<endl;
		cin>>G->V>>G->E;

		G->adj= (int **)malloc(G->V * sizeof(int *)); 
	    	for (int i=0; i<G->V; i++) 
		G->adj[i] = (int *)malloc(G->V * sizeof(int)); 

		for(int i=0;i<G->V;i++)
			for(int j=0;j<G->V;j++)
				G->adj[i][j]=0;

		for(int i=0;i<G->E;i++)
		{
			cout<<endl<<"Enter Reading Edge v ---> u and weight :"<<endl;
			cin>>v>>u>>w;
			G->adj[v][u]=w;//weight
			
			//G->adj[v][u]=1;
			//G->adj[u][v]=1;
		}
		return G;
	}
}


template<typename T>
void GraphAlgo<T>::DFS(struct Graph *G)
{
int ck;
int *visited=(int *)malloc(sizeof(G->V)*sizeof(int *));
for(int i=0;i<G->V;i++)
visited[i]=0;

visited[0]=1;
stack<int> st;
st.push(0);
cout<<"DFS data:"<<endl<<st.top();
	while(!st.empty())
	{
	        ck=st.top();
		for(int i=0;i<G->V;i++)
		{
			if(G->adj[ck][i])
			 {
				if(visited[i])
				continue;
				else
				{
				visited[i]=1;
				st.push(i);	
				cout<<"  "<<st.top();
				break;
				}
		         }
		}
		if(ck==st.top())
		st.pop();
	}
}



template<typename T>
void GraphAlgo<T>::BFS(struct Graph *G)
{
int ck;
int *visited=(int *)malloc(sizeof(G->V)*sizeof(int *));
for(int i=0;i<G->V;i++)
visited[i]=0;

visited[0]=1;
queue<int> q;
q.push(0);
cout<<endl<<"BFS data:"<<endl<<q.back();
	while(!q.empty())
	{
	        ck=q.front();
		q.pop();
		for(int i=0;i<G->V;i++)
		{
			if(G->adj[ck][i])
			 {
				if(visited[i])
				continue;
				else
				{
				visited[i]=1;
				q.push(i);	
				cout<<"  "<<q.back();
				}
		         }
		}
	}
}


template<typename T>
void GraphAlgo<T>::topologicalSort(struct Graph *G)
{
int *indegree=GraphAlgo<T>::getIndegree(G);
int count=0;
queue<int> q;
cout<<endl<<"Topological Order:"<<endl;
for(int i=0;i<G->V;i++)
	if(indegree[i]==0)
		q.push(i);
while(!q.empty())
{
	int v=q.front();
	cout<<"  "<<v;
	count++;
	q.pop();
	for(int i=0;i<G->V;i++)
		if(G->adj[v][i] && (--indegree[i]==0))
				q.push(i);				
}

if(count!=G->V)
cout<<endl<<"Graph has cycle";
}

template<typename T>
void GraphAlgo<T>::show(struct Graph *G)
{
cout<<"Vertices: "<<G->V<<endl;
cout<<"Edges: "<<G->E<<endl;
cout<<"Whole Matrix:"<<endl;
for(int i=0;i<G->V;i++)
{	
	for(int j=0;j<G->V;j++)
	cout<<G->adj[i][j]<<"  ";
	cout<<endl;
}
}


template<typename T>
void GraphAlgo<T>::unweightedSortedPath(struct Graph *G,int s,int d)
{
if((s<0 || s>G->V) || (d<0 || d>G->V))
{
cout<<endl<<"Invalid source and destination value "<<endl;
return;
}
int *path=(int *)malloc(sizeof(G->V)*sizeof(int *));
int *distance=(int *)malloc(sizeof(G->V)*sizeof(int *));
for(int i=0;i<G->V;i++)
{
path[i]=-1;
distance[i]=-1;
}

queue<int> q;
q.push(s);
path[s]=s;
distance[s]=0;


while(!q.empty())
{
	int v=q.front();
	q.pop();
	for(int i=0;i<G->V;i++)
		if(G->adj[v][i]==1 && distance[i]==-1)
		  {
			distance[i]=distance[v]+1;
			path[i]=v;
			q.push(i);
		  }
}

cout<<endl<<" Unweighted distance sequence :"<<endl;
for(int i=0;i<G->V;i++)
cout<<"  "<<distance[i];
cout<<endl;

cout<<endl<<" Unweighted sorted path from "<<s<<" to "<<d<<endl;
for(int i=0;i<G->V;i++)
cout<<"  "<<path[i];
cout<<endl;
}


template<typename T>
void GraphAlgo<T>::dijkstraSortedPath(struct Graph *G)
{
if(G)
{
	int *path=(int *)malloc(sizeof(G->V)*sizeof(int *));
	int *distance=(int *)malloc(sizeof(G->V)*sizeof(int *));
	for(int i=0;i<G->V;i++)
	{
		path[i]=-1;
		distance[i]=-1;
		if(i==0)
		{
			path[i]=0;
			distance[i]=0;
		}
	}

	PriorityQueue<T> *pq=new PriorityQueue<T>();
	(*pq).add(0,0);
	T v;
	while(!(*pq).isEmpty())
	{	
		v=(*(*pq).getFront()).getData();
		(*pq).popFront();
					
		for(int i=0;i<G->V;i++)
		{
			int weight=G->adj[v][i];
			if(weight > 0)
			{
				int tValue=distance[v]+weight;
				if((distance[i]==-1) || (distance[i]!=-1 && tValue<distance[i]) )
				{
					distance[i] =tValue;
					path[i]=v;
					(*pq).add(i,distance[i]);
				}
			}
		}	
	} 

	cout<<endl<<"Dijkastra's Algorithm"<<endl;
	cout<<"Distance sequence:"<<endl;
	for(int i=0;i<G->V;i++)
		cout<<"  "<<distance[i];
		cout<<endl;
	cout<<"Path sequence:"<<endl;
	for(int i=0;i<G->V;i++)
		cout<<"  "<<path[i];
		cout<<endl;
}

}





int main()
{
GraphAlgo<int> *gl=new GraphAlgo<int>();
struct Graph *G=(*gl).create();
(*gl).show(G);
(*gl).DFS(G);
(*gl).BFS(G);
(*gl).topologicalSort(G);
(*gl).unweightedSortedPath(G,0,5);
(*gl).dijkstraSortedPath(G);
return 0;
}

