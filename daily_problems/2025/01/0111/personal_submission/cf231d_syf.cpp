// Problem: D. Magic Box
// Contest: Codeforces - Codeforces Round 143 (Div. 2)
// URL: https://codeforces.com/problemset/problem/231/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// DateTime : 2025-01-11 11:54:05
// Author : sunyafei
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
	int x,y,z;cin>>x>>y>>z;
	int x1,y1,z1;cin>>x1>>y1>>z1;
	vector<int> a(6);
	for(int&x:a)cin>>x;
	vector<int> b={0,y1,0,z1,0,x1},c={-1,1,-1,1,-1,1},d={y,y,z,z,x,x};
	int ans=0;
	for(int i=0;i<6;i++){
		if(c[i]<0){
			if(d[i]<b[i]) ans+=a[i];
		}else{
			if(d[i]>b[i]) ans+=a[i];
		}
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
