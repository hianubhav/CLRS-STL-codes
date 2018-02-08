#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void bfs(vector<vector<int> >&adj,int s)
{
	int V = adj.size();
	vector<int>visited(V,0);
	vector<int>parent(V,-1);
	vector<int>d(V,-1);
	visited[s]=1;
	d[s]=0;
	queue<int>q;
	q.push(s);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i=0;i<adj[u].size();i++){
			int v=adj[u][i];
			if(!visited[v]){
				q.push(v);
				visited[v]=1;
				parent[v]=u;
				d[v]=d[u]+1;
			}
		}
		cout<<u<<" d="<<d[u]<<" p="<<parent[u]<<endl;
	}
}
void addEdge(vector<vector<int> >&adj,int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

int main()
{

	int V,E;
	cin>>V;
	cin>>E;
	vector<vector<int> >adj(V);
	for(int i=0;i<E;i++){
		int u,v;
		cin>>u>>v;
		addEdge(adj,u,v);
	}
	bfs(adj,0);
}