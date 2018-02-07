#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;

int partition(vi &a,int low,int high)
{
	int pivot = a[high];
	int i = low-1;
	for(int j=low;j<high;j++){
		if(a[j]<=pivot){
			i+=1;
			swap(a[i],a[j]);
		}
	}
	swap(a[i+1],a[high]);
	return i+1;
}

int randomPartition(vi &a,int low,int high)
{
	int k = rand()%(high-low+1)+low;
	swap(a[k],a[high]);
	return partition(a,low,high);
}

void quickSort(vi &a, int low, int high)
{
	if(low<high){
		int pivot = randomPartition(a,low,high);
		cout<<pivot<<" "<<a[pivot]<<endl;
		quickSort(a,low,pivot-1);
		quickSort(a,pivot+1,high);
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
	quickSort(a,0,n-1);
	for(int i=0;i<n;i++)
		cout<<a[i]<<endl;
}