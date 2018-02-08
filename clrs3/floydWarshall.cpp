#include<bits/stdc++.h>
#define vi vector<int>
#define ii pair<int,int>
using namespace std;
void add_edge(vector<vector<ii > >&g,int u,int v,int w)
{
	g[u].push_back(make_pair(v,w));
}
void initialize_all_source(vector<vector<ii > >&g,vector<vi > &sol,vector<vi > &p)
{
	for(int i=0;i<g.size();i++)
		sol[i][i]=0;
	for(int u=0;u<g.size();u++){
		for(int j=0;j<g[u].size();j++){
			int v=g[u][j].first;
			int w=g[u][j].second;
			sol[u][v]=w;
			p[u][v]=u;
		}
	}
}
void floydWarshall(vector<vector<ii > >&g,vector<vi >&sol,vector<vi >&p)
{
	int nv = g.size();
	initialize_all_source(g,sol,p);
	for(int k=0;k<nv;k++){
		for(int i=0;i<nv;i++){
			for(int j=0;j<nv;j++){
				if(sol[i][j]>sol[i][k]+sol[k][j]){
					sol[i][j]=sol[i][k]+sol[k][j];
					p[i][j] = p[k][j];
				}
			}
		}
	}
}
void printSolution(vector<vi >&sol,vector<vi >&p)
{
	int nv=sol.size();
	cout<<"distance matrix:"<<endl;
	for(int i=0;i<nv;i++){
		for(int j=0;j<nv;j++){
			cout<<sol[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<"parent matrix:"<<endl;
		for(int i=0;i<nv;i++){
		for(int j=0;j<nv;j++){
			cout<<p[i][j]<<"\t";
		}
		cout<<endl;
	}
}
void printPath(vector<vi >&p,int i,int j){
	stack<int>path;
	while(i!=j){
		path.push(j);
		j=p[i][j];
	}
	path.push(i);
	while(!path.empty()){
		cout<<path.top();path.pop();
		if(!path.empty()){
			cout<<"->";
		}
	}
	cout<<endl;
}
int main()
{
	int nv,ne;
	cin>>nv>>ne;
	vector<vector<ii > > g(nv);
	for(int i=0;i<ne;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add_edge(g,u,v,w);
	}
	vector<vi >sol(nv,vi(nv,999999)),p(nv,vi(nv,-1));
	floydWarshall(g,sol,p);
	printSolution(sol,p);
	cout<<"paths are :"<<endl;
	for(int i=0;i<nv;i++){
		for(int j=0;j<nv;j++){
			printPath(p,i,j);
		}

	}
}
