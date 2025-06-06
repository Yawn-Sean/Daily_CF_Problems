/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int N=1010;

int st[N][N][5][5];

void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<std::vector<char>> g(n,std::vector<char> (m));

    int sx,sy,ex,ey;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            std::cin>>g[i][j];
            if(g[i][j]=='S') sx=i,sy=j;
            else if(g[i][j]=='T') ex=i,ey=j;
        }
    }
    bool flag=0;

    std::vector<int> dx={1,0,-1,0},dy={0,-1,0,1};
    std::vector<int> v={1,2,1,2};

    auto dfs=[&](auto self,int x,int y,int d,int cnt)->void{
        if(cnt>2 or st[x][y][d][cnt]) return;
        if(x==ex and y==ey){
            flag=1;
            return;
        }
        st[x][y][d][cnt]=1;
        for(int i=0;i<4;i++){
            int nx=x+dx[i],ny=y+dy[i];
            if(nx<0 or nx>=n or ny<0 or ny>=m or g[nx][ny]=='*') continue;
            self(self,nx,ny,v[i],cnt+(d==(3-v[i])));
        }
    };

    dfs(dfs,sx,sy,0,0);

    std::cout<<(flag ? "YES" : "NO")<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
