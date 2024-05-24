// Problem: D. Circular Dance
// Contest: Codeforces - Codeforces Round 529 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1095/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms

/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define all(x) x.begin(),x.end()
#define pb push_back

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) "lengli"
#endif

const int N=100010;

void solve(){
	int n;
	cin>>n;
	vector<array<int,2>> a(n+2);
	for(int i=1;i<=n;i++) cin>>a[i][0]>>a[i][1];
	
	vector<int> res;
	
	auto check=[&](int t){
		res.clear();
		vector<int> ne(n+2,-1);
		ne[1]=a[1][t];
		ne[ne[1]]=a[1][t^1];
		int st=ne[1];
		res.pb(st);
		while(st!=1){
			int u=a[st][0],v=a[st][1];
			if(ne[st]==v) swap(u,v);
			if(ne[u]!=-1 and ne[u]!=v) return 0;
			ne[u]=v;
			st=u;
			res.pb(st);
		}
		return 1;
	};
	
	if(check(0)){
		for(auto x:res) cout<<x<<" ";
	}else if(check(1)){
		for(auto x:res) cout<<x<<" ";
	}
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
