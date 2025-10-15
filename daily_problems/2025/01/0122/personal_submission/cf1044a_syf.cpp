// Problem: A. The Tower is Going Home
// Contest: Codeforces - Lyft Level 5 Challenge 2018 - Final Round
// URL: https://codeforces.com/problemset/problem/1044/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// DateTime : 2025-01-22 10:42:34
// Author : sunyafei
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
	int n,m;cin>>n>>m;
	vector<int> a(n);
	for(int&x:a)cin>>x;
	vector<int> b;
	for(int i=0;i<m;i++){
		int l,r,y;cin>>l>>r>>y;
		if(l==1) b.push_back(r);
	}
	a.push_back(1000000000);
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	int k=b.size();
	int ans=k;
	for(int i=0;i<n+1;i++){
		int j=lower_bound(b.begin(),b.end(),a[i])-b.begin();
		ans=min(ans,i+k-j);
	}
	cout<<ans;
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
