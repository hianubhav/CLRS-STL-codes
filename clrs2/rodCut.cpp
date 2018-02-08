#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;
//example 10 1 5 8 9 10 17 17 20 24 30
int rod_cut_helper(vi &p,vi &r,vi &s, int l)
{
	if(r[l]>0)
		return r[l];
	if(l==0)
		return 0;
	for(int i=1;i<=l;i++){
		int temp = rod_cut_helper(p,r,s,l-i);
		if(p[i]+temp > r[l]){
			r[l] = p[i]+temp;
			s[l] = i;
		}
	}
	return r[l];
}
void printSolution(vi&s, int l)
{
	if(l<=0)
		return;
	cout<<s[l]<<endl;
	printSolution(s,l-s[l]);
}
int rod_cut(vi&p, vi&s, int l)
{
	vi r(l+1,INT_MIN);
	return rod_cut_helper(p,r,s,l);
}
int main()
{
	int n,l;
	vi p(1,0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int temp;
		cin>>temp;
		p.push_back(temp);
	}
	vi s(n+1,0);
	cout<<"enter the length of rod : ";
	cin>>l;
	cout<<"profit : "<<rod_cut(p,s,l)<<endl;
	cout<<"solution : "<<endl;
	printSolution(s,l);
}