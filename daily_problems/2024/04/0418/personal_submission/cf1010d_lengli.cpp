// Problem: D. Mars rover
// Contest: Codeforces - Codeforces Round 499 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1010/D
// Memory Limit: 256 MB
// Time Limit: 5000 ms

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
	vector<string> tp(n+1);
	vector<vector<int>> eg(n+1);
	vector<int> a(n+1,-1);
	for(int i=1;i<=n;i++){
		cin>>tp[i];
		if(tp[i]=="IN") cin>>a[i];
		else if(tp[i]=="NOT"){
			int x;
			cin>>x;
			eg[i].pb(x);
		}else{
			int x,y;
			cin>>x>>y;
			eg[i].pb(x),eg[i].pb(y);
		}
	}
	
	function<int(int,int)> dfs=[&](int u,int fa){
		if(a[u]!=-1) return a[u];
		if(tp[u]=="AND") a[u]=dfs(eg[u][0],u)&dfs(eg[u][1],u);
		if(tp[u]=="XOR") a[u]=dfs(eg[u][0],u)^dfs(eg[u][1],u);
		if(tp[u]=="OR") a[u]=dfs(eg[u][0],u)|dfs(eg[u][1],u);
		if(tp[u]=="NOT") a[u]=!dfs(eg[u][0],u);
		return a[u];
	};
	
	dfs(1,0);
	
	vector<int> st(n+1,0);
	
	function<void(int,int)> dfs1=[&](int u,int fa){
		if(st[u]) return;
		st[u]=1;
		if(tp[u]=="IN") return;
		if(tp[u]=="AND"){
			int l=eg[u][0],r=eg[u][1];
			if(a[u]) dfs1(l,u),dfs1(r,u);
			else if(a[l]) dfs1(r,u);
			else if(a[r]) dfs1(l,u);
		}
		if(tp[u]=="XOR"){
			int l=eg[u][0],r=eg[u][1];
			dfs1(l,u),dfs1(r,u);
		}
		if(tp[u]=="OR"){
			int l=eg[u][0],r=eg[u][1];
			if(a[l] and a[r]) return;
			if(a[l]) dfs1(l,u);
			else if(a[r]) dfs1(r,u);
			else dfs1(l,u),dfs1(r,u);
			
		}
		if(tp[u]=="NOT") dfs1(eg[u][0],u);
	};
	
	dfs1(1,0);
	
	for(int i=1;i<=n;i++){
		if(tp[i]=="IN"){
			if(st[i]) cout<<(a[1]^1);
			else cout<<a[1];
		}
	}
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
