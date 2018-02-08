#include<bits/stdc++.h>
#define  vi vector<int>
using namespace std;
struct edge
{
	int u,v,w;
	edge(int _u,int _v,int _w)
	{
		u = _u;
		v = _v;
		w = _w;
	}
};

void printSolution(vector<edge> &sol)
{
	for(int i=0;i<sol.size();i++){
		cout<<sol[i].u<<" "<<sol[i].v<<" "<<sol[i].w<<endl;
	}
}

bool compare(const struct edge x,const struct edge y)
{
	return x.w<y.w;
}

void make_set(int x, vi &p,vi &rank)
{
	p[x]=x;
	rank[x]=0;
}

int find_set(int x,vi &p)
{
	if(p[x] != x){
		p[x] = find_set(p[x],p);
	}
	return p[x];
}

void link_set(int x, int y, vi &p, vi &rank)
{
	if(rank[x]>rank[y]){
		p[y]=x;
	}
	else
	{
		p[x]=y;
		if(rank[x] == rank[y])
			rank[y]++;
	}
}

void union_set(int x,int y,vi &p,vi &rank)
{
	int px = find_set(x,p);
	int py = find_set(y,p);
	link_set(px,py,p,rank);
}

void kruskal (int n,vector<edge>&e,vector<edge>&sol)
{
	sort(e.begin(),e.end(),compare);
//	cout<<"sorted edges "<<endl;
//	printSolution(e);
	vi p(n,-1),rank(n,0);
	for(int i = 0;i<n;i++){
		make_set(i,p,rank);
	}
	for(int i=0;i<e.size();i++){
		if(find_set(e[i].u,p) != find_set(e[i].v,p)){
			sol.push_back(e[i]);
			union_set(e[i].u,e[i].v,p,rank);
//			cout<<"edge + "<<e[i].u<<"-"<<e[i].v<<"("<<e[i].w<<")"<<endl;
		}
		else{
//			cout<<"edge - "<<e[i].u<<"-"<<e[i].v<<"("<<e[i].w<<")"<<endl;
		}
	}
}

int main()
{
	int n;
	cin>>n;
	vector<edge>e;
	int ne;
	cin>>ne;
	for(int i=0;i<ne;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e.push_back(edge(u,v,w));
	}
	vector<edge>sol;
	kruskal(n,e,sol);
	cout<<endl<<"final set is "<<endl;
	printSolution(sol);
}