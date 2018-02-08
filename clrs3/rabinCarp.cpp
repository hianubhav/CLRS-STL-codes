#include<bits/stdc++.h>
using namespace std;

int rabinCarp(string pat, string text)
{
	int count = 0;
	int m = pat.length(),n = text.length();
	int q = 101,d=128,h=1;
	for(int i=1;i<m;i++)
		h = (h*d)%q;

	int p=0,t=0;
	for(int i=0;i<m;i++){
		p = (d*p+pat[i])%q;
		t = (d*t+text[i])%q;
	}

	for(int i=0;i<=n-m;i++){
		cout<<p<<" "+text.substr(i,m)+" "<<t<<endl;
		if(p==t){
			if(text.substr(i,m) == pat){
				count++;
				cout<<"pattern at index : "<<i<<endl;
			}
		}

		if(i<n-m)
			t = (d*(t-h*text[i])+text[m+i])%q;
			if(t<0)
				t+=q;
	}
	return count;
}


int main()
{
	string pat,text;
	int n;
	cin>>n;
	cout<<"hello"<<endl;
	getline(cin,pat);
	getline(cin,text);
	cout<<rabinCarp(pat,text)<<endl;
}