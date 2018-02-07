#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;
int partition(vi &a, int low, int high)
{
	int x = a[high];
	int i=low-1;
	for(int j=low;j<high;j++){
		if(a[j]<=x){
			i++;
			swap(a[j],a[i]);
		}
	}
	swap(a[i+1],a[high]);
	return i+1;
}

int quickSelect(vi &a, int low, int high, int k)
{
	if(k>high || k<low){
		cout<<"error"<<endl;
		return -1;
	}
	int pivot = partition(a,low,high);
	if(pivot == k)
		return a[pivot];
	if(pivot > k)
		return quickSelect(a,low,pivot-1,k);
	if(pivot < k)
		return quickSelect(a,pivot+1,high,k);
}

int main()
{
	vi a;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		a.push_back(temp);
	}
	int k;
	cout<<"k : ";
	cin>>k;
	cout<<quickSelect(a,0,n-1,k-1)<<endl;
}