// Problem: President and Roads
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF567E
// Memory Limit: 250 MB
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

int n,m,s,t;

void solve(){
	cin>>n>>m>>s>>t;
	vector<vector<array<int,2>>> eg(n+1),reg(n+1);
	vector<array<int,3>> edge;
	vector<bool> st(m+1,0);
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		edge.pb({u,v,w});
		eg[u].pb({v,w});
		reg[v].pb({u,w});
	}	
	
	auto ds=dijkstra(s,eg);
	auto dt=dijkstra(t,reg);
	
	debug(ds,dt);
	
	tj.init(n);
	for(int i=0;i<m;i++){
		auto [u,v,w]=edge[i];
		if(ds[u]!=-1 and dt[v]!=-1 and ds[u]+dt[v]+w==ds[t]){
			debug(u,v);
			tj.add(u,v,i);
		}
	}
	tj.tarjan();
	
	for(int i=0;i<m;i++){
		auto [u,v,w]=edge[i];
		if(tj.is_bridge[i]){
			cout<<"YES"<<endl;
		}else{
			int ans=ds[t]-ds[u]-dt[v]-1;
			if(ans<=0 or ds[u]==-1 or dt[v]==-1) cout<<"NO"<<endl;
			else {
				cout<<"CAN"<<" "<<w-ans<<endl;
			}
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
