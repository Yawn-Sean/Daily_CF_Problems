/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int N=210;

int n,m;
char g[N][N];
int st[N][N][4];
int use[N][N];

int tmp=0,cnt=0;

void clear(){
    tmp=0;
    std::memset(st,0,sizeof st);
    std::memset(use,0,sizeof use);
}

std::array<int,3> get(int x,int y,int fx){
    if(g[x][y]=='\\'){
        if(fx==0) return {x,y-1,3};
        if(fx==1) return {x+1,y,2};
        if(fx==2) return {x,y+1,1};
        if(fx==3) return {x-1,y,0};
    }else if(g[x][y]=='/'){
        if(fx==0) return {x,y+1,1};
        if(fx==1) return {x-1,y,0};
        if(fx==2) return {x,y-1,3};
        if(fx==3) return {x+1,y,2};
    }else{
        if(fx==0) return {x-1,y,0};
        if(fx==1) return {x,y+1,1};
        if(fx==2) return {x+1,y,2};
        if(fx==3) return {x,y-1,3};
    }
    return {0,0,0};
};

void dfs(int x,int y,int fx){
    if(st[x][y][fx]) return;
    st[x][y][fx]=1;
    if(g[x][y]=='\\'){
        if(!use[x][y]){
            tmp++;
            use[x][y]=1;
        }
    }
    if(g[x][y]=='/'){
        if(!use[x][y]){
            tmp++;
            use[x][y]=1;
        }
    }
    auto [nx,ny,nfx]=get(x,y,fx);
    if(nx<0 or nx>n or ny<0 or ny>m) return;
    dfs(nx,ny,nfx);
}

void solve(){
    std::cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            std::cin>>g[i][j];
            if(g[i][j]=='\\') cnt++;
            if(g[i][j]=='/') cnt++;
        }
    }

    std::vector<std::string> res;

    for(int j=1;j<=m;j++){
        clear();
        dfs(1,j,2);
        if(tmp==cnt){
            std::string ans="N";
            ans+=std::to_string(j);
            res.pb(ans);
        }
    }
    for(int j=1;j<=m;j++){
        clear();
        dfs(n,j,0);
        if(tmp==cnt){
            std::string ans="S";
            ans+=std::to_string(j);
            res.pb(ans);
        }
    }
    for(int i=1;i<=n;i++){
        clear();
        dfs(i,1,1);
        if(tmp==cnt){
            std::string ans="W";
            ans+=std::to_string(i);
            res.pb(ans);
        }
    }
    for(int i=1;i<=n;i++){
        clear();
        dfs(i,m,3);
        if(tmp==cnt){
            std::string ans="E";
            ans+=std::to_string(i);
            res.pb(ans);
        }
    }
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
