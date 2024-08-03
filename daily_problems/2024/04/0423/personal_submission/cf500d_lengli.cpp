// Problem: D. New Year Santa Network
// Contest: Codeforces - Good Bye 2014
// URL: https://codeforces.com/problemset/problem/500/D
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
#define double long double
#define LL __int128

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) "lengli"
#endif

const int N=100010;

int n;
vector<array<int,3>> eg[N]; 
int cnt[N];
int sz[N],w[N];

int get(int k){
	int l=k,r=n-k;
	int ans=(r>=2 ? l*(r-1)*r : 0ll);
	ans+=(l>=2 ? r*(l-1)*l : 0ll);
	return ans;
}

void dfs(int u,int f){
	for(auto [x,w,id]:eg[u]){
		if(x==f) continue;
		dfs(x,u);
		cnt[id]+=get(sz[x]);
		sz[u]+=sz[x];
	}
	sz[u]+=1;
}

void solve(){
	cin>>n;
	for(int i=1;i<n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		w[i]=c;
		eg[a].pb({b,c,i});
		eg[b].pb({a,c,i});
	}
	
	dfs(1,0);
	LL sum=0;
	for(int i=1;i<n;i++) sum+=(LL)cnt[i]*w[i];
	int count=(n-2)*(n-1)*n/6;
	
	int q;
	cin>>q;
	while(q--){
		int id,x;
		cin>>id>>x;
		sum-=(LL)cnt[id]*w[id];
		w[id]=x;
		sum+=(LL)cnt[id]*w[id];
		cout<<fixed<<setprecision(10)<<(double)sum/(double)count<<endl;
		
	}
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
