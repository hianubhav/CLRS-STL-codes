#include<iostream>
#include<queue>
#define vi vector<int>
#define ii pair<int,int>
using namespace std;
int popCount = 0,relaxCount=0;
void initialize_single_source(vi &p,vi &d,int s)
{
	d[s]=0;
}
class compare
{
public:
	int operator()(ii a,ii b){
		return a.second>b.second;
	}
};
relax(int u,int v,int w,vi &d,vi &p,priority_queue<ii,vector<ii >,compare >&q)
{
	if(d[v]>d[u]+w){
		d[v]=d[u]+w;
		p[v]=u;
		q.push(make_pair(v,d[v]));									// to know why this works reading topcoder tutorial is highly recomended
	}
}
void dijkstra(vector<vector<ii > >&g, vi &p, vi &d,int s)
{
	initialize_single_source(p,d,s);
	priority_queue<ii ,vector<ii >,compare> q;
	q.push(make_pair(s,0));
	while(!q.empty()){
		int u = q.top().first;
		int du = q.top().second;
		q.pop();
		popCount++;
		cout<<"popped : "<<u<<" "<<du<<endl;
		//so that same node does not get visited twice(if du > d[u] then node is already visited when du was d[u])
		//jo node pop ho raha hai uske neighbours queue mein daalo aur phir node ko visited karo
		if(du<=d[u]){
			for(int i=0;i<g[u].size();i++){
				int v = g[u][i].first;
				int w = g[u][i].second;
				relaxCount++;
				relax(u,v,w,d,p,q);
			}
		}

	}
}
void printSolution(vi &p, vi &d)
{
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
	vi p(nv,-1),d(nv,INT_MAX);
	int s;
	cout<<"single source : ";
	cin>>s;
	dijkstra(g,p,d,s);
	printSolution(p,d);
	cout<<endl<<"relax count : "<<relaxCount<<endl;
}

/*

*/

