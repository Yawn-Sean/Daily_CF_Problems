/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int N=100010,M=19;

int n,m;
int st[N];
std::vector<int> eg[N];

int p[N];
int find(int x){
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}
void merge(int a,int b){
    a=find(a),b=find(b);
    if(a==b) return;
    p[a]=b;
}

int fa[N][M];
int dep[N];

void dfs(int u,int f){
    for(int i=1;i<M;i++){
        fa[u][i]=fa[fa[u][i-1]][i-1];
    }
    st[u]=1;
    for(auto j:eg[u]){
        if(j==f) continue;
        fa[j][0]=u;
        dep[j]=dep[u]+1;
        dfs(j,u);
    }
}

int lca(int a,int b){
    if(dep[a]<dep[b]) std::swap(a,b);
    for(int i=M-1;i>=0;i--){
        if(dep[a]-(1<<i)>=dep[b]) a=fa[a][i];
    }
    if(a==b) return a;
    for(int i=M-1;i>=0;i--){
        if(fa[a][i]!=fa[b][i]){
            a=fa[a][i];
            b=fa[b][i];
        }
    }
    return fa[a][0];
}

void build(){
    for(int i=1;i<=n;i++){
        if(i==find(i)){
            dfs(i,0);
        }
    }
}

std::array<int,2> work[N];
int idx=0;

void solve(){
    std::cin>>n>>m;
    for(int i=0;i<=n;i++) {
        p[i]=i;
        eg[i].clear();
        st[i]=0;
    }

    std::vector<std::array<int,2>> qr;

    for(int i=0;i<m;i++){
        int op;
        std::cin>>op;
        if(op==1){
            int x,y;
            std::cin>>x>>y;
            eg[x].pb(y);
            eg[y].pb(x);
            merge(x,y);
        }else if(op==2){
            int x;
            std::cin>>x;
            int top=find(x);
            work[++idx]={x,top};
        }else{
            int x,id;
            std::cin>>x>>id;
            qr.pb({x,id});
        }
    }
    build();
    for(auto [x,id]:qr){
        auto [l,r]=work[id];

        if(lca(l,x)==x and lca(x,r)==r) std::cout<<"YES"<<"\n";
        else std::cout<<"NO"<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
