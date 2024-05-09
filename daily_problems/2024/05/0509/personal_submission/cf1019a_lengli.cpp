// Problem: A. Elections
// Contest: Codeforces - Codeforces Round 503 (by SIS, Div. 1)
// URL: https://codeforces.com/problemset/problem/1019/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms

/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define all(x) x.begin(),x.end()
#define pb push_back
#define int long long

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) "lengli"
#endif

const int N=100010;

void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> q(m+1);
	int cnt=0;
	for(int i=1;i<=n;i++){
		int p,c;
		cin>>p>>c;
		if(p==1) cnt++;
		else q[p].pb(c);
	}
	
	for(int i=2;i<=m;i++) sort(all(q[i]));
	
	auto check=[&](int x)->int{
		int res=0,ct=cnt;
		vector<int> a;
		for(int i=2;i<=m;i++){
			if(q[i].size()>=x){
				int nd=q[i].size()-x+1;
				if(nd>q[i].size()) return 1e18;
				ct+=nd;
				for(int j=0;j<nd;j++) res+=q[i][j];
				for(int j=nd;j<q[i].size();j++) a.pb(q[i][j]);
			}else{
				for(auto x:q[i]) a.pb(x);
			}
		}
		sort(all(a));
		debug(a);
		for(int i=0;i<x-ct;i++) res+=a[i];
		return res;
		
	};
	
	int res=1e18;
	for(int i=cnt;i<=n;i++){
		res=min(res,check(i));
	}
	cout<<res;
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
