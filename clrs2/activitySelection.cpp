#include<bits/stdc++.h>
using namespace std;
class activity
{
public:
	int id;
	int s;
	int f;
	activity(int _id,int _s, int _f)
	{
		id = _id;
		s = _s;
		f = _f;
	}
};
bool compare (const activity &a,const activity &b)
{
	return a.f < b.f;
}
printActivity(vector<activity> &a)
{
	cout<<"activities in vector :"<<endl;
	for(int i=0;i<a.size();i++){
		cout<<a[i].id<<endl;
	}
}
void activitySelection(vector<activity> &a,vector<activity> &sol)
{
	int  n = a.size();
	sort(a.begin(),a.end(),compare);
	sol.push_back(a[0]);
	int k=0;
	for(int i=1;i<n;i++){
		if(a[i].s > a[k].f){
			sol.push_back(a[i]);
			k=i;
		}
	}
}

int main()
{
	int n;
	cin>>n;
	vector<activity>a,sol;
	for(int i=0;i<n;i++){
		int s,f;
		cin>>s>>f;
		a.push_back(activity(i,s,f));
	}
	activitySelection(a,sol);
	printActivity(sol);
}