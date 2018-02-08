#include<iostream>
#include<vector>
#include<stack>
#define vi vector<int>
#define ii pair<int,int>
using namespace std;

void initialize_single_source(vector<vector<ii > >&g,vi &p, vi &d,int s)
{
	for(int i=0;i<g.size();i++){
		p[i]=-1;
		d[i]=INT_MAX;
	}
	d[s]=0;
}

void relax(int u, int v, int wuv, vi &d, vi &p)
{
	if(d[v] > d[u] + wuv){
		d[v] = d[u] + wuv;
		p[v]=u;
	}
}

void dfs_visit(vector<vector<ii > >&g,int s,stack<int>&st,vi &visited)
{
	visited[s] =1;
	for(int i = 0;i<g[s].size();i++)
	{
		int v = g[s][i].first;
		if(!visited[v]){
			dfs_visit(g,v,st,visited);
		}
	}
	st.push(s);
}

void topological(vector<vector<ii > >&g,stack<int>&st)
{
	vi visited(g.size(),0);
	for(int i=0;i<g.size();i++)
		if(!visited[i])
			dfs_visit(g,i,st,visited);
}
void shortest_path(vector<vector<ii > >&g,vi &p, vi &d, int s)
{
	stack<int>st;
	topological(g,st);
	initialize_single_source(g,p,d,s);
	while(st.top()!=s){
//		cout<<st.top()<<endl;  reaching to the source
		st.pop();
	}
	while(!st.empty()){
		int u = st.top();
		st.pop();
		for(int i=0;i<g[u].size();i++){
			int v = g[u][i].first;
			int wuv = g[u][i].second;
			relax(u,v,wuv,d,p);
		}
	}
}
void printSolution(vi &p, vi &d , int s)
{
	cout<<"solution"<<endl;
	for(int i=0;i<p.size();i++)
		cout<<i<<" "<<p[i]<<" "<<d[i]<<endl;
}
void add_edge(vector<vector<ii > >&g,int u,int v,int w)
{
	g[u].push_back(make_pair(v,w));
}
int main()
{
	int nv,ne,s;
	cin>>nv>>ne;
	vector<vector<ii > >g(nv);
	for(int i=0;i<ne;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add_edge(g,u,v,w);
	}
	vi p(nv,-1),d(nv,INT_MAX);
	cout<<"enter source : ";
	cin>>s;
	shortest_path(g,p,d,s);
	printSolution(p,d,s);

}