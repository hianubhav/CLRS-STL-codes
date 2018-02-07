#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;
void insertion(vi &v)
{
	int n=v.size();
	for(int i=1;i<n;i++){
		int k=v[i],j=i-1;
		while(j>=0 && v[j]>k){
			v[j+1]=v[j];
			j--;
		}
		v[j+1]=k;
	}
}

int main()
{
	int n;
	cin>>n;
	vi v;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		v.push_back(t);
	}
	insertion(v);
	for(int i=0;i<n;i++){
		cout<<v[i]<<endl;
	}
}