// Problem: B. World Tour
// Contest: Codeforces - Codeforces Round 349 (Div. 1)
// URL: https://codeforces.com/problemset/problem/666/B
// Memory Limit: 512 MB
// Time Limit: 5000 ms

/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

const int N=100010;

void solve(){
	int n,m;
	std::cin>>n>>m;
	std::vector<std::vector<int>> eg(n+2);
	for(int i=1;i<=m;i++){
		int a,b;
		std::cin>>a>>b;
		eg[a].pb(b);
	}
	
	std::vector<std::vector<std::array<int,2>>> pr(n+2);
	std::vector<std::vector<std::array<int,2>>> ne(n+2);
	
	auto update=[&](std::vector<std::vector<std::array<int,2>>> &q,int u,int v,int w){
		if(q[u].size()<3) q[u].pb({w,v});
		else{
			std::vector<std::array<int,2>> p;
			for(auto x:q[u]) p.pb(x);
			p.pb({w,v});
			sort(all(p),std::greater<>());
			while(p.size()>3) p.pop_back();
			q[u]=p;
		}
	};
	
	std::vector<std::vector<int>> dist(n+2);
	for(int i=1;i<=n;i++){
		auto &d=dist[i];
		d.resize(n+2,-1);
		std::vector<int> st(n+2,0);
		std::queue<int> q;
		d[i]=0;
		q.push(i);
		while(q.size()){
			auto t=q.front();
			q.pop();
			if(st[t]) continue;
			st[t]=1;
			for(auto x:eg[t]){
				if(st[x]) continue;
				if(d[x]==-1 or d[x]>d[t]+1){
					d[x]=d[t]+1;
					q.push(x);
				}
			}
		}
		for(int j=1;j<=n;j++){
			if(d[j]!=-1){
				update(pr,j,i,d[j]);
				update(ne,i,j,d[j]);
			}
		}
	}
	
	int res=0;
	std::vector<int> k;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(dist[i][j]==-1 or i==j) continue;
			for(auto [w,u]:pr[i])
				for(auto [ww,v]:ne[j]){
					if(u==v) continue;
					if(u==i or u==j) continue;
					if(v==i or v==j) continue;
					int ans=dist[u][i]+dist[i][j]+dist[j][v];
					if(ans>res){
						std::vector<int> id={u,i,j,v};
						res=ans;
						k=id;
					}
				}
		}
	}
	for(auto x:k) std::cout<<x<<" ";
	
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
