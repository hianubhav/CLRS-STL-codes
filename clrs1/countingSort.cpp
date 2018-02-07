#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;

void countingSort(vi &a)
{
	int amax=0;
	int n=a.size();
	for(int i=0;i<n;i++){
		if(a[i]>amax)
			amax=a[i];
	}
	
	vector<int>C(amax+1,0),b(n+1,0);
	for(int i=0;i<n;i++)
		C[a[i]]++;
	for(int i=1;i<=amax;i++)
		C[i]=C[i]+C[i-1];

	for(int i=n-1;i>=0;i--){
		b[C[a[i]]]= a[i];
		C[a[i]]--;
	}
	for(int i=0;i<=n;i++)
		a[i]=b[i+1];

}

int main()
{
	int n;
	cin>>n;
	vi a;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		a.push_back(temp);
	}
	countingSort(a);
	for(int i=0;i<n;i++)
		cout<<a[i]<<endl;
}