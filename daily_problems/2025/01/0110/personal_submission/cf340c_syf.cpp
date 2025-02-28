// Problem: C. Tourist Problem
// Contest: Codeforces - Codeforces Round 198 (Div. 2)
// URL: https://codeforces.com/problemset/problem/340/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// DateTime : 2025-01-10 16:30:29
// Author : sunyafei
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
	int n;cin>>n;
	vector<int> a(n);
	for(int&x:a)cin>>x;
	sort(a.begin(),a.end());
	int ans=0;
	for(int i=0;i<n;i++){
		ans+=(4*i-2*n+3)*a[i];
	}
	int g=gcd(ans,n);
	cout<<ans/g<<" "<<n/g;
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
