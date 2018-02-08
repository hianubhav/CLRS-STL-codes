#include<bits/stdc++.h>
#define vi vector<int>
// example 6 30 35 15 5 10 20 25
using namespace std;
void matrixChain(vi &p,vector<vi >&m,vector<vi >&s)
{
	int n = p.size()-1;
	for(int i=0;i<n;i++)
		m[i][i]=0;
	for(int l = 2;l<=n;l++){
		for(int i=0;i<=n-l;i++){
			int j=i+l-1;
			for(int k=i;k<j;k++){
				int ksol = m[i][k]+m[k+1][j]+p[i]*p[k+1]*p[j+1];
				if(ksol < m[i][j]){
					m[i][j]=ksol;
					s[i][j]=k;
				}
			}
		}
	}
}
void printSolution(vector<vi >&s,int i,int j)
{
	if(i==j)
		cout<<" A"<<i<<" ";
	else{
		cout<<"( ";
		printSolution(s,i,s[i][j]);
		printSolution(s,s[i][j]+1,j);
		cout<<" )";
	}
}
int main()
{
	int n;
	cin>>n;
	vi p;
	for(int i=0;i<=n;i++){
		int temp;
		cin>>temp;
		p.push_back(temp);
	}
	vector<vi >m(n,vi(n,INT_MAX));
	vector<vi >s(n,vi(n,0));
	matrixChain(p,m,s);
	cout<<endl<<"solution is "<<m[0][n-1]<<endl<<endl;;
	printSolution(s,0,n-1);cout<<endl;
}