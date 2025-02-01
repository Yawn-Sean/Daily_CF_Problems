/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int N=1500,M=1000010,INF=2e9;

struct MF {
  int h[N], e[M], ne[M], w[M], idx = 0;
  int vis[N];
  
  int n, S, T;
  int maxflow = 0;
  int dep[N], cur[N];

  void init(int n_,int S_,int T_) {
    n=n_,S=S_,T=T_;
    maxflow=0;
    memset(h, -1, sizeof h);
    idx = 0;
  }

  void add(int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
    e[idx] = a, ne[idx] = h[b], w[idx] = 0, h[b] = idx++;
  }

  bool bfs() {
    std::queue<int> q;
    memset(dep, -1, sizeof dep);
    dep[S] = 0;
    q.push(S);
    cur[S] = h[S];
    while (q.size()) {
      int u = q.front();
      q.pop();
      for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (dep[j] == -1 and w[i]) {
          dep[j] = dep[u] + 1;
          cur[j] = h[j];
          if (j == T) return 1;
          q.push(j);
        }
      }
    }
    return 0;
  }

  int dfs(int u, int limit) {
    if (u == T or !limit) return limit;
    int flow = 0;
    for (int i = cur[u]; ~i and flow < limit; i = ne[i]) {
      cur[u] = i;
      int j = e[i];
      if (dep[j] == dep[u] + 1 and w[i]) {
        int t = dfs(j, std::min(limit - flow, w[i]));
        if (!t) dep[j] = -1;
        w[i] -= t;
        w[i ^ 1] += t;
        flow += t;
      }
    }
    return flow;
  }

  void dinic() {
    while (bfs()) {
      memcpy(cur, h, sizeof h);
      maxflow += dfs(S, INF);
    }
  }
} mf;

void solve(){
    int n,m,k;
    std::cin>>n>>m>>k;

    int S=n+m+5,T=n+m+6;

    mf.init(n+m+10,S,T);

    std::vector<int> rd(n+2,0);
    std::vector<std::vector<int>> id(n+2);

    for(int i=1;i<=m;i++){
        int u,v;
        std::cin>>u>>v;
        rd[u]++,rd[v]++;
        mf.add(i+n,T,1);
        id[u].pb(i),id[v].pb(i);
    }

    bool flag=1;

    int cnt=0;

    for(int i=1;i<=n;i++){
        if(rd[i]<=k) continue;
        if(rd[i]>2*k){
            flag=0;
            break;
        }
        int dlt=(rd[i]-k)*2;
        cnt+=dlt;
        mf.add(S,i,dlt);
        for(auto x:id[i]){
            mf.add(i,x+n,1);
        }
    } 

    mf.dinic();

    auto maxflow=mf.maxflow;

    if(!flag or maxflow!=cnt){
        for(int i=1;i<=m;i++){
            std::cout<<0<<" ";
        }std::cout<<"\n";
        return;
    }

    std::vector<int> res(m+2,-1);

    int idx=1;

    for(int i=1;i<=n;i++){
        if(rd[i]<=k) continue;
        std::vector<int> tmp;
        for(int j=mf.h[i];j!=-1;j=mf.ne[j]){
            int v=mf.e[j];
            if(!mf.w[j]) tmp.pb(v-n);
        }
        for(int j=0;j<tmp.size();j+=2){
            res[tmp[j]]=res[tmp[j+1]]=idx;
            idx++;
        }
    } 

    for(int i=1;i<=m;i++) if(res[i]==-1) res[i]=idx,idx++;

    for(int i=1;i<=m;i++) std::cout<<res[i]<<" ";
    std::cout<<"\n";
    
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
