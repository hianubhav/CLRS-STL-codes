#include<bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vi>
using namespace std;

struct node
{
	int task;
	struct node *next_task;
};
struct node *head = NULL;

void add_task(int task)
{
	struct node* temp = (struct node *)malloc(sizeof(struct node));
	temp->task = task;
	temp->next_task = head;
	head = temp;
}

void dfs_visit(vvi &adj,int u,vi &visited)
{
	visited[u]=true;
	cout<<u<<endl;
	for(int i=0;i<adj[u].size();i++){
		int v = adj[u][i];
		if(!visited[v]){
			dfs_visit(adj,v,visited);
		}
	}
	add_task(u);
}

void topological_sort(vvi &adj)
{
	int V = adj.size();
	vector<int>visited(V,0);
	for(int i=0;i<V;i++){
		if(!visited[i]){
			dfs_visit(adj,i,visited);
		}
	}
}


void printlist()
{
	struct node *iter = head;
	while(iter != NULL){
		cout<<iter->task<<"-->";
		iter = iter->next_task;
	}
}
void add_Edge(vvi &adj,int u,int v)
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
		add_Edge(adj,u,v);
	}
	topological_sort(adj);
	printlist();
}