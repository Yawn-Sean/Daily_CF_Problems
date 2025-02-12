/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int N=200010;

int n;
std::vector<int> eg[N];
int col[N];

std::vector<int> res;

void dfs(int u,int fa){
    for(auto x:eg[u]){
        if(x==fa) continue;
        res.pb(x);
        col[x]^=1;
        dfs(x,u);
        res.pb(u);
        col[u]^=1;
    }
    for(auto x:eg[u]){
        if(!col[x]){
            res.pb(x);
            col[x]^=1;
            res.pb(u);
            col[u]^=1;
        }
    }
}

void solve(){
    std::cin>>n;
    int cnt=0;
    for(int i=1;i<=n;i++) {
        std::cin>>col[i];
        if(col[i]==-1) col[i]=0;
        cnt+=col[i];
    }
    if(cnt==n){
        std::cout<<1<<"\n";
        return;
    }
    for(int i=1;i<n;i++){
        int u,v;
        std::cin>>u>>v;
        eg[u].pb(v);
        eg[v].pb(u);
    }
    res.pb(1);

    dfs(1,0);

    if(!col[1]){
        res.pb(eg[1][0]);
        col[eg[1][0]]^=1;
        res.pb(1);
        col[1]^=1;
        res.pb(eg[1][0]);
        col[eg[1][0]]^=1;
    }
    for(auto x:res) std::cout<<x<<" ";std::cout<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
