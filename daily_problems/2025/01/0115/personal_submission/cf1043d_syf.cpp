// Problem: D. Mysterious Crime
// Contest: Codeforces - Codeforces Round 519 by Botan Investments
// URL: https://codeforces.com/problemset/problem/1043/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// DateTime : 2025-01-15 19:53:38
// Author : sunyafei
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
	int n,m;cin>>n>>m;
	vector<vector<int>> a(m,vector<int>(n));
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++)cin>>a[i][j];
	}
	vector<int> perm(n+1);
	for(int i=1;i<=n;i++){
		perm[a[0][i-1]]=i;
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			a[i][j]=perm[a[i][j]];
		}
	}
	vector<int> mn(n+1,n);
	for(int i=0;i<m;i++){
		int cur=0;
		for(int j=0;j<n;j++){
			if(cur<j) cur++;
			while(cur+1<n&&a[i][cur+1]==a[i][cur]+1){
				cur++;
			}
			mn[a[i][j]]=min(mn[a[i][j]],a[i][cur]);
		}
	}
	int ans=0,cur=1;
	while(cur<=n){
		int x=mn[cur]-cur+1;
		ans+=x*(x+1)/2;
		cur=mn[cur]+1;
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
