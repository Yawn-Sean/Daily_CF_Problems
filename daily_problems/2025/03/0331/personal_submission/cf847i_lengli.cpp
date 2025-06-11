/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

void solve(){
    int n,m,q,p;
    std::cin>>n>>m>>q>>p;
    std::vector<std::vector<char>> g(n+2,std::vector<char> (m+2));
    std::vector<std::array<int,2>> zy;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            std::cin>>g[i][j];
            if(g[i][j]!='.' and g[i][j]!='*') zy.pb({i,j});
        }
    }

    std::vector<std::vector<int>> cnt(n+2,std::vector<int> (m+2,0));
    std::vector<std::vector<int>> st(n+2,std::vector<int> (m+2,0));
    std::vector<int> dx={1,0,-1,0},dy={0,-1,0,1};

    auto bfs=[&](auto xx,auto yy){
        for(auto &t:st) std::fill(all(t),0);
        std::queue<std::array<int,3>> que;
        que.push({xx,yy,(g[xx][yy]-'A'+1)*q});
        while(que.size()){
            auto [x,y,v]=que.front();
            que.pop();
            if(st[x][y]) continue;
            st[x][y]=1;
            cnt[x][y]+=v;
            for(int i=0;i<4;i++){
                int nx=x+dx[i],ny=y+dy[i];
                if(nx<1 or nx>n or ny<1 or ny>m or g[nx][ny]=='*' or v<=0) continue;
                que.push({nx,ny,v/2});
            }
        }
    };

    for(auto [x,y]:zy) bfs(x,y);

    int res=0;
    for(auto x:cnt) 
        for(auto y:x) res+=y>p;
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
