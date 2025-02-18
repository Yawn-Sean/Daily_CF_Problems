/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define int long long

constexpr int N=300010;

int n,m,k;
std::vector<std::array<int,3>> eg[N];
std::array<int,2> fa[N];

std::vector<int> dijkstra(int S){
	std::vector<int> dist(n+1,-1);
	std::vector<bool> st(n+1,0);
	std::priority_queue<std::array<int,2>,std::vector<std::array<int,2>>,std::greater<std::array<int,2>>> q;
	q.push({0,S});dist[S]=0;
	while(q.size()){
		auto t=q.top();
		q.pop();
		if(st[t[1]]) continue;
		st[t[1]]=1;
		for(auto [x,w,id]:eg[t[1]]){
			if(dist[x]==-1 or dist[x]>t[0]+w){
				dist[x]=t[0]+w;
                fa[x]={t[1],id};
				q.push({dist[x],x});
			}
		}
	}
	return dist;
}

void solve(){
    std::cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        std::cin>>u>>v>>w;
        eg[u].pb({v,w,i});
        eg[v].pb({u,w,i});
    }
    dijkstra(1);
    std::vector<std::vector<std::array<int,2>>>  neg(n+2);
    for(int i=2;i<=n;i++){
        auto [v,w]=fa[i];
        neg[v].pb({i,w});
        neg[i].pb({v,w});
    }

    int cnt=0;
    std::vector<int> res;
    auto dfs=[&](auto self,int u,int fa){
        if(cnt>=k) return;
        for(auto [v,id]:neg[u]){
            if(v==fa) continue;
            if(cnt<k){
                cnt++;
                res.pb(id);
            }
            self(self,v,u);
        }
    };

    dfs(dfs,1,0);
    std::cout<<res.size()<<"\n";
    for(auto x:res) std::cout<<x<<" ";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
