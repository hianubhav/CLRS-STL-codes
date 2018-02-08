#include<bits/stdc++.h>
#define vi vector<int>
#define ii pair<int,int>
using  namespace std;
class compare
{
public:
	int operator()(ii a,ii b)
	{
		return a.second>b.second;
	}
};
void prim(vector<vector<ii > >&g,vi &p, vi &key,int s )
{
	vi visited(g.size(),0);
	priority_queue<ii, vector<ii>,compare>q;
	for(int i = 0;i<g.size();i++){
		q.push(make_pair(i,key[i]));
	}
	q.push(make_pair(s,0));
	while(!q.empty()){
		ii top = q.top();
		int  u = top.first;
//		cout<<u<<endl;
		q.pop();
		visited[u]=1;
		for(int i=0;i<g[u].size();i++){
			int v = g[u][i].first;
			int w = g[u][i].second;
			if(!visited[v] && w < key[v]){
				key[v]=w;
				p[v]=u;
				q.push(make_pair(v,w));
			}
		}
	}
}
void printSolution(vi &p,vi &key)
{
	for(int i=1;i<p.size();i++){
		cout<<i<<" "<<p[i]<<" "<<key[i]<<endl;
	}
}
void  add_edge(vector<vector<ii > >&g,int u,int v,int w)
{
	g[u].push_back(make_pair(v,w));
	g[v].push_back(make_pair(u,w));
}
int main()
{
	int nv,ne;
	cin>>nv>>ne;
	vector<vector<ii > >g(ne);
	for(int i=0;i<ne;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add_edge(g,u,v,w);
	}
	vi p(nv,-1),key(ne,INT_MAX);
	prim(g,p,key,0);
	cout<<"spanning tree is : "<<endl;
	printSolution(p,key);
}