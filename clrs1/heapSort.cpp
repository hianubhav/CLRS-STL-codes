#include<bits/stdc++.h>
#define vi vector<int>

using namespace std;
int heapSize=0;

void maxHeapify(vi &a,int i)
{
	int l = 2*i;
	int r = 2*i+1;
	int largest = i;
	if(l<=heapSize && a[largest] < a[l]){
		largest = l;
	}
	if(r<=heapSize && a[largest] < a[r]){
		largest = r;
	}
	if(largest != i){
		swap(a[i],a[largest]);
		maxHeapify(a,largest);
	}
}

void buildMaxHeap(vi &a)
{
	heapSize = a.size()-1;
	for(int i=a.size()/2;i>=1;i--){
		maxHeapify(a,i);
	}
}

void heapSort(vi &a)
{
	int n = a.size()-1;
	for(int i=1;i<=n;i++){
		swap(a[1],a[heapSize]);
		heapSize--;
		maxHeapify(a,1);
	}
}

void increaseKey(vi &a, int i, int k)
{
	if(a[i] > k){
		cout<<"key not increasing"<<endl;
		return;
	}
	a[i]=k;
	int p = i/2;
	while(p>=1 &&a[p]<a[i]){
		swap(a[p],a[i]);
		i=p;
		p/=2;
	}
}

void insert(vi &a,int x)
{
	a.push_back(INT_MIN);
	heapSize++;
	increaseKey(a,heapSize,x);
}



int top(vi &a)
{
	if(heapSize == 0)
		return -1;
	return a[1];
}

int extractMax(vi &a)
{
	if(heapSize == 0)
		return -1;
	int max = a[1];
	swap(a[1],a[heapSize]);
	heapSize--;
	maxHeapify(a,1);
	return max;
}


int main()
{
	int arr[]={4,1,3,2,16,9,10,14,8,7};
	vector<int>a(1,INT_MIN);
	vector<int>b(1,INT_MIN);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		insert(a,arr[i]);
		b.push_back(arr[i]);
	}
	heapSort(a);
	buildMaxHeap(b);

	heapSize=10;
	heapSort(b);
	for(int i=0;i<a.size();i++)
		cout<<a[i]<<" "<<b[i]<<endl;
}