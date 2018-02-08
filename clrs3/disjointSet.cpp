#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;

void make_set(int i,vi &p,vi &rank)
{
	p[i]=i;
	rank[i]=0;
}
int find_set(int x,vi &p)
{
	if(p[x] != x){
		p[x]=find_set(p[x],p);
	}
	return p[x];
}
void link(int x, int y, vi &p, vi &rank)
{
	if(rank[x]>rank[y]){
		p[y]=x;
	}
	else{
		p[x]=y;
		if(rank[x]== rank[y]){
			rank[y]++;
		}
	}
}
void union_set(int  x, int y, vi &p, vi &rank)
{
	link(find_set(x,p),find_set(y,p),p,rank);
}
bool same_component(int x,int y,vi &p){
	if(find_set(x,p) == find_set(y,p))
		return true;
	return false;
}
int main()
{
	int n;
	cin>>n;
	vi p(n,-1),rank(n,-1);
	for(int i=0;i<n;i++){
		make_set(i,p,rank);
	}
	int edges;
	cin>>edges;
	for(int i=0;i<edges;i++){
		int x,y;
		cin>>x>>y;
		if(find_set(x,p) != find_set(y,p)){
			union_set(x,y,p,rank);
		}
	}
	cout<<"node\tparent\trank"<<endl;
	for(int i=0;i<n;i++){
		cout<<i<<"\t"<<p[i]<<"\t"<<rank[i]<<endl;
	}
}
