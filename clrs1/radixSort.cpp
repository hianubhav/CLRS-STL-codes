#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;

int digit(int k,int d){
	int divisor = pow(10,d-1);
	return (k/divisor)%10;
}

int digits(int k){
	int d=0;
	while(k){
		d++;
		k/=10;
	}
	return d;
}
int findmax(vi &a)
{
	int n=a.size(),amax=0;
	for(int i=0;i<n;i++)
		if(a[i]>amax)
			amax=a[i];
	return amax;
}

void countingSort(vi &a,int d)
{
	int n = a.size();
	vector<int>C(10,0),b(n+1,0);
	for(int i=0;i<n;i++){
		int aid = digit(a[i],d);
		C[aid]++;
	}
	for(int i=1;i<=9;i++)
		C[i]=C[i-1]+C[i];

	for(int i=n-1;i>=0;i--){
		int aid = digit(a[i],d);
		b[C[aid]]=a[i];
		C[aid]--;
	}
	for(int i=0;i<n;i++)
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
	int amax = findmax(a);
	int ndigits = digits(amax);
	for(int d=1;d<=ndigits;d++){
			cout<<endl;
		countingSort(a,d);
		cout<<endl;
			for(int i=0;i<n;i++)
		cout<<a[i]<<endl;
	}

}