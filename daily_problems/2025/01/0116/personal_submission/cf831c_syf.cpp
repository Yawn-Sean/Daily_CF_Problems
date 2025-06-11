// Problem: C. Jury Marks
// Contest: Codeforces - Codeforces Round 424 (Div. 2, rated, based on VK Cup Finals)
// URL: https://codeforces.com/problemset/problem/831/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// DateTime : 2025-01-16 20:31:22
// Author : sunyafei
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
	int k,n;cin>>k>>n;
	vector<int> a(k);
	for(int&x:a)cin>>x;
	vector<int> pre(k);
	partial_sum(a.begin(),a.end(),pre.begin());
	vector<int> b(n);
	for(int&x:b)cin>>x;
	int ans=0;
	set<int> st,vis;
	for(int i=0;i<k;i++){
		int d=b[0]-pre[i];
		if(vis.count(d)) continue;
		vis.insert(d);
		st.clear();
		for(int j=0;j<k;j++){
			st.insert(d+pre[j]);
		}
		bool flg=true;
		for(int j=0;j<n;j++){
			if(!st.count(b[j])){
				flg=false;
				break;
			}
		}
		if(flg) ans++;
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
