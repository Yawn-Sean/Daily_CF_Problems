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
    int n,m;
    std::cin>>n>>m;
    std::vector<std::vector<char>> g(n,std::vector<char> (m));
    std::vector<std::vector<char>> st(n,std::vector<char> (m,0));
    for(auto &y:g) for(auto &x:y) std::cin>>x;

    std::vector<std::array<int,3>> res;
    std::vector<int> dx={1,0,-1,0},dy={0,-1,0,1};

    int sx=-1,sy=-1;

    auto dfs=[&](auto self,int x,int y)->void{
        if(st[x][y]) return;
        st[x][y]=1;
        res.pb({0,x+1,y+1});
        for(int i=0;i<4;i++){
            int nx=x+dx[i],ny=y+dy[i];
            if(nx<0 or nx>=n or ny<0 or ny>=m or g[nx][ny]=='#') continue;
            self(self,nx,ny);
        }
        if(x!=sx or y!=sy) {
            res.pb({2,x+1,y+1});
            res.pb({1,x+1,y+1});
        }
    };

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]=='.'){
                sx=i,sy=j;
                dfs(dfs,i,j);
            }
        }  
    } 

    std::cout<<res.size()<<"\n";
    for(auto [c,x,y]:res){
        std::cout<<(c==0 ? "B" : c==1 ? "R" : "D")<<" "<<x<<" "<<y<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
