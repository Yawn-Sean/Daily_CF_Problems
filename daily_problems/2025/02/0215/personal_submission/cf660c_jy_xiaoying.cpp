#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/660/C
//格式化：ctrl + shift + a
//2025-2-16

const int MAX=3e5+10;
int nums[MAX];
int n,k;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>n>>k;
	for(int i=0; i<n; i++) {
		cin>>nums[i];
	}
	int l=0,r=0;
	int left=0,right=0;
	int ans=0,sum=0;
	for(; r<n; r++) {
		sum+=nums[r];
		while(r-l+1>sum+k) {
			sum-=nums[l];
			l++;
		}
		if(r-l+1>ans) {
			left=l,right=r;
			ans=r-l+1;
		}
	}
	if(k>0) {
		for(; left<=right; left++) {
			nums[left]=1;
		}
	}

	cout<<ans<<endl;
	for(int i=0; i<n; i++) {
		cout<<nums[i]<<" ";
	}

	return 0;
}
