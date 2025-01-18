// Problem: E. Counting Rectangles
// Contest: Codeforces - Codeforces Round 817 (Div. 4)
// URL: https://codeforces.com/problemset/problem/1722/E
// Memory Limit: 256 MB
// Time Limit: 6000 ms
// DateTime : 2025-01-18 19:46:45
// Author : sunyafei
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
	int n,q;cin>>n>>q;
	vector<vector<int>> pre(1001,vector<int>(1001));
	for(int i=0;i<n;i++){
		int x,y;cin>>x>>y;
		pre[x][y]+=x*y;
	}
	for(int i=0;i<=1000;i++){
		for(int j=0;j<1000;j++){
			pre[i][j+1]+=pre[i][j];
		}
	}
	for(int i=0;i<1000;i++){
		for(int j=0;j<=1000;j++){
			pre[i+1][j]+=pre[i][j];
		}
	}
	while(q--){
		int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
		cout<<pre[x2-1][y2-1]-pre[x1][y2-1]-pre[x2-1][y1]+pre[x1][y1]<<"\n";
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t=1;
	cin>>t;
	while(t--){
		solve();
		// if(t)cout<<"\n";
	}
	return 0;
}
