#include<bits/stdc++.h>
using namespace std;
int ptime = 0;

void dfs_visit(vector<vector<int> >&adj, int s, vector<int> &visited, vector<int> &parent,
					vector<pair<int,int> >&t)
{
	t[s].first = ptime++;
	visited[s]=1;
	cout<<s<<endl;

	for(int i=0;i<adj[s].size();i++){
		int v=adj[s][i];
		if(visited[v] && t[v].second == -1 ){
			cout<<"cycle and back-edge detected "<<s<<" -> "<<v<<endl;
		}
		if(!visited[v]){
			parent[v]=s;
			dfs_visit(adj,v,visited,parent,t);
		}
	}
	t[s].second=ptime++;
//	cout<<s<<" d= "<<t[s].first<<" f= "<<t[s].second<<" p= "<<parent[s]<<endl;
}

void dfs(vector<vector<int> > &adj)
{
	int V=adj.size();
	vector<int> visited(V,0);
	vector<int> parent(V,0);
	vector<pair<int,int> >t(V,make_pair(-1,-1));
	for(int i=0;i<V;i++){
		if(!visited[i]){
			cout<<"connected component"<<endl;
			parent[i]=-1;
			dfs_visit(adj,i,visited,parent,t);
		}
	}
}


void addEdge(vector<vector<int> >&adj,int u,int v)
{
	adj[u].push_back(v);
}
int main()
{
	int V,E;
	cin>>V>>E;
	vector<vector<int> >adj(V);
	while(E--){
		int u,v;
		cin>>u>>v;
		addEdge(adj,u,v);
	}

	dfs(adj);

}