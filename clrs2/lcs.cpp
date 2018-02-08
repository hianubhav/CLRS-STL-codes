#include<bits/stdc++.h>
using namespace std;
class sol
{
public:
	int c;
	char d;
	sol(int _c,char _d){
		c = _c;
		d = _d;
	}
};
void printSolutionMatrix(vector<vector<sol> >&s)
{
	int m = s.size();
	int n = s[0].size();
	for(int i=1;i<m;i++){
		for(int j=1;j<n;j++)
			cout<<s[i][j].c<<s[i][j].d<<" ";
	cout<<endl;
	}
}
void printLCS(vector<vector<sol> >&s,string x, int m, int n)
{
	if(m==0 || n==0)
		return;

	if(s[m][n].d == 'd'){
		printLCS(s,x,m-1,n-1);
		cout<<x[m-1];
	}
	else if(s[m][n].d == 'u')
		printLCS(s,x,m-1,n);
	else
		printLCS(s,x,m,n-1);
}
void lcs(vector<vector<sol> >&s, string x, string y)
{
	int m=x.length();
	int n=y.length();
	for(int i=0;i<m;i++)
	for(int j=0;j<n;j++){
		if(x[i]==y[j]){
			s[i+1][j+1].c = s[i][j].c+1;
			s[i+1][j+1].d = 'd';
		}
		else if(s[i+1][j].c >= s[i][j+1].c){
			s[i+1][j+1].c = s[i+1][j].c;
			s[i+1][j+1].d = 'l';
		}
		else{
			s[i+1][j+1].c = s[i][j+1].c;
			s[i+1][j+1].d = 'u';
		}
	}
}
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	int m=s1.length(),n=s2.length();
	vector<vector<sol> >s(m+1,vector<sol>(n+1,sol(0,'u')));
	lcs(s,s1,s2);
	printSolutionMatrix(s);
	cout<<"LCS length : "<<s[m][n].c<<endl;
	cout<<"LCS : ";
	printLCS(s,s1,m,n);
}