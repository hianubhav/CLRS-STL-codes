#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;
void merge(vi &v,int low,int mid,int high)
{
	vi L,R;
	for(int i=low;i<=mid;i++)
		L.push_back(v[i]);
	for(int j=mid+1;j<=high;j++)
		R.push_back(v[j]);

	R.push_back(INT_MAX);
	L.push_back(INT_MAX);
	int k=low;
	int n1=0,n2=0;
	while(k<=high){
		if(L[n1]<=R[n2]){
			v[k]=L[n1];
			k++;n1++;
		}
		else{
			v[k]=R[n2];
			k++;n2++;
		}
	}
}
void mergeSort(vi &v,int low,int high)
{
	if(low<high){
		int mid = (low+high)/2;
		mergeSort(v,low,mid);
		mergeSort(v,mid+1,high);
		merge(v,low,mid,high);
	}
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
	mergeSort(a,0,n-1);
	for(int i=0;i<n;i++)
		cout<<a[i]<<endl;
}