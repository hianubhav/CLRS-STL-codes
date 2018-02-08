#include<bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vi>
using namespace std;
stack<int>s;

void dfs_visit(vvi &adj,int u,vi &visited,int forssc)				//forssc=1 for transpose and 0 for original graph
{
	visited[u]=1;
	if(forssc){
		cout<<u<<endl;
	}
	for(int i=0;i<adj[u].size();i++){
		int v = adj[u][i];
		if(!visited[v]){
			dfs_visit(adj,v,visited,forssc);
		}
	}
	if(!forssc){
		s.push(u);													//pushing node in stack when it finishes
	}
}

void dfs(vvi &adj,int forssc)
{
	int V = adj.size();
	vi visited(V,0);
	if(!forssc){
		for(int i=0;i<V;i++){
			if(!visited[i]){
				dfs_visit(adj,i,visited,forssc);
			}
		}
	}
	else{
		int k=1;
		while(!s.empty()){
			int i = s.top();
			s.pop();

			if(!visited[i]){
				cout<<"Strongly Connected Component "<<k++<<endl;
				dfs_visit(adj,i,visited,forssc);
			}
		}
	}
}
vvi transpose(vvi &adj)
{
	int V = adj.size();
	vvi adjt(V);
	for(int i=0;i<V;i++){
		for(int j=0;j<adj[i].size();j++){
			int u=adj[i][j];
			adjt[u].push_back(i);
		}
	}
	return adjt;
}
void ssc(vvi &adj)
{
	dfs(adj,0);
	vvi adjt = transpose(adj);
	dfs(adjt,1);
}
void addEdge(vvi &adj,int u,int v)
{
	adj[u].push_back(v);
}
int main()
{
	int V,E;
	cin>>V>>E;
	vvi adj(V);
	for(int i=0;i<E;i++){
		int u,v;
		cin>>u>>v;
		addEdge(adj,u,v);
	}
	ssc(adj);
}