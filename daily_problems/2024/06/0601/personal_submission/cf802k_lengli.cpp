// Problem: K. Send the Fool Further! (medium)
// Contest: Codeforces - Helvetic Coding Contest 2017 online mirror (teams allowed, unrated)
// URL: https://codeforces.com/problemset/problem/802/K
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

int n,k;
vector<array<int,2>> eg[N];
int f[N][2];

void dfs(int u,int fa){
	vector<array<int,2>> g;
	int sum=0;
	for(auto [x,w]:eg[u]){
		if(x==fa) continue;
		dfs(x,u);
		g.pb({f[x][0]+w,f[x][1]+w});
	}
	sort(all(g),greater<>());
	
	for(int i=0;i<min((int)g.size(),k-1);i++) sum+=g[i][0];
	f[u][0]=sum;
	
	for(int i=0;i<g.size();i++){
		int ans=(i<k-1 ? sum-g[i][0]+g[i][1]+(g.size()>=k ? g[k-1][0] : 0ll) : sum+g[i][1]);
		f[u][1]=max(f[u][1],ans);
	}
}

void solve(){
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		eg[a].pb({b,c});
		eg[b].pb({a,c});
	}
	
	dfs(0,-1);
	
	cout<<f[0][1];
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
