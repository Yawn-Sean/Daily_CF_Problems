// Problem: D. Nastya Is Buying Lunch
// Contest: Codeforces - Codeforces Round 546 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1136/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// DateTime : 2025-01-13 19:43:24
// Author : sunyafei
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
	int n,m;cin>>n>>m;
	vector<int> a(n),vis(n+1);
	vector<vector<int>> g(n+1);
	for(int&x:a)cin>>x;
	while(m--){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
	}
	vis[a[n-1]]=1;
	int cnt=1;
	for(int i=n-2;i>=0;i--){
		int v=0;
		for(int x:g[a[i]]){
			v+=vis[x];
		}
		if(v<cnt){
			vis[a[i]]=1;
			cnt++;
		}
	}
	cout<<n-cnt;
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
