/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

const int N=1010;

int n,m,S,T;
std::vector<int> eg[N];

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
		for(auto x:eg[t[1]]){
			if(dist[x]==-1 or dist[x]>t[0]+1){
				dist[x]=t[0]+1;
				q.push({dist[x],x});
			}
		}
	}
	return dist;
}

std::bitset<N> edge[N];

void solve(){
	std::cin>>n>>m>>S>>T;
    for(int i=1;i<=m;i++){
        int u,v;
        std::cin>>u>>v;
        eg[v].pb(u);
        eg[u].pb(v);
        edge[u][v]=edge[v][u]=1;
    }
    auto l=dijkstra(S);
    auto r=dijkstra(T);

    int res=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(edge[i][j] or i==j) continue;
            if(l[i]+r[j]+1>=l[T] and l[j]+r[i]+1>=l[T]) {
                res++;
            }
        }
    }
    std::cout<<res/2;
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
