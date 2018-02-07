#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;

int maxCrossSum(vi &v,int low,int mid,int high)
{
	int ls=0,sum=0,rs=0;
	for(int i=mid-1;i>=low;i--){
		sum+=v[i];
		if(sum>ls)
			ls=sum;
	}
	sum=0;
	for(int i=mid+1;i<=high;i++){
		sum+=v[i];
		if(sum>rs)
			rs=sum;
	}
	return rs+ls+v[mid];
}

int maxSubarray(vi &v,int low,int  high)
{
	if(high==low)
		return v[low];
	int ls=0,rs=0,cs=0;
	if(low<high){
		int mid = (low+high)/2;
		ls=maxSubarray(v,low,mid-1);
		rs=maxSubarray(v,mid+1,high);
		cs=maxCrossSum(v,low,mid,high);
	}
	return (ls>rs)?(ls>cs?ls:cs):(rs>cs?rs:cs);
}

//Kadane's Algorithm
int maxSubArray(vi &A) {
    int max_till_now=0,max_at_i=0,g_start_i=-1,g_end_i=-1,l_start_i=0;
    for(int i=0;i<A.size();i++){
        max_at_i+=A[i];
        if(max_at_i > max_till_now){
            max_till_now=max_at_i;
            g_start_i=l_start_i;
            g_end_i=i;
        }
        if(max_at_i<=0){
            max_at_i=0;
            l_start_i=i+1;
        }
    }
    cout<<g_start_i<<g_end_i<<endl;
    return max_till_now;

}
int main()
{
	int n;
	cin>>n;
	vi v;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		v.push_back(temp);
	}
	int s=maxSubarray(v,0,n-1)
	cout<<"ans is "<<s<<endl;		//CLRS solution
	int s=maxSubArray(v);
	cout<<"ans is "<<s<<endl;		//Kadane's solution
}