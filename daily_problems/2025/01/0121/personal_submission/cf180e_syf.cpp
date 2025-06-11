// Problem: E. Cubes
// Contest: Codeforces - Codeforces Round 116 (Div. 2, ACM-ICPC Rules)
// URL: https://codeforces.com/problemset/problem/180/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// DateTime : 2025-01-21 20:07:21
// Author : sunyafei
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
	int n,m,k;cin>>n>>m>>k;
	vector<int> a(n);
	for(int&x:a)cin>>x;
	vector<int> cnt(m+1);
	auto check=[&](int mid){
		fill(cnt.begin(),cnt.end(),0);
		int m=min(n,mid+k);
		for(int i=0;i<m;i++){
			if(++cnt[a[i]]>=mid) return true;
		}
		for(int i=m;i<n;i++){
			cnt[a[i-m]]--;
			if(++cnt[a[i]]>=mid) return true;
		}
		return false;
	};
	
	int l=1,r=n;
	while(l<=r){
		int mid=l+(r-l)/2;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	cout<<r;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t=1;
	// cin>>t;
	while(t--){
		solve();
		if(t)cout<<"\n";
	}
	return 0;
}
