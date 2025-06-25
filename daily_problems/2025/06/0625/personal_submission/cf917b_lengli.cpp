/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int N=110;
int n,m;
std::vector<std::array<int,2>> eg[N];
int st[N][N][30];
int sg[N][N][30];

int dfs(int u,int v,int la){
    if(st[u][v][la]) return sg[u][v][la];
    st[u][v][la]=1;
    bool flag=0;
    for(auto [x,ne]:eg[u]){
        if(ne<la) continue;
        int t=dfs(v,x,ne);
        if(!t) flag=1;
    }
    return sg[u][v][la]=flag;
}

char res[N][N];

void solve(){
    std::cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        char c;
        std::cin>>u>>v>>c;
        int w=c-'a'+1;
        eg[u].pb({v,w});
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            res[i][j]=dfs(i,j,0) ? 'A' : 'B';
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) std::cout<<res[i][j];
        std::cout<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
