#include<bits/stdc++.h>
#define vi vector<int>
#define ii pair<int,int>
using namespace std;
void initialize_single_source(vi &p,vi &d,int s)
{
	d[s]=0;
}
void relax(int u,int v,int w,vi &p,vi &d)
{
	if(d[v]>d[u]+w){
		d[v]=d[u]+w;
		p[v]=u;
	}
}
bool bellmanFord(vector<vector<ii > >&g,vi &p, vi &d,int s)
{
	initialize_single_source(p,d,s);
	int nv = g.size();
	for(int k=0;k<nv-1;k++){
		for(int u=0;u<nv;u++){
			for(int j=0;j<g[u].size();j++){
				int v = g[u][j].first;
				int w = g[u][j].second;
				relax(u,v,w,p,d);
			}
		}
	}
	//for negative weight cycle detection
		for(int u=0;u<nv;u++){
			for(int j=0;j<g[u].size();j++){
				int v = g[u][j].first;
				int w = g[u][j].second;
				if(d[v]>d[u]+w)
					return false;			//cycle detected thus returning true
			}
		}
		return true;
}
void printSolution(vi &p,vi &d)
{
	cout<<"solution is "<<endl;
	for(int i=0;i<p.size();i++){
		cout<<i<<" "<<p[i]<<" "<<d[i]<<endl;
	}
}
void add_edge(vector<vector<ii > >&g,int u,int v,int w)
{
	g[u].push_back(make_pair(v,w));
}
int main()
{
	int nv,ne;
	cin>>nv>>ne;
	vector<vector<ii > >g(nv);
	for(int i=0;i<ne;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add_edge(g,u,v,w);
	}
	vi p(nv,-1),d(nv,999999);
	int s;
	cout<<"source : ";
	cin>>s;
	if(!bellmanFord(g,p,d,s)){
		cout<<"negative weight cycle found"<<endl;
	}
	else{
		printSolution(p,d);
	}
}