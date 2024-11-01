/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<std::vector<char>> g(n+2,std::vector<char> (m+2));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) std::cin>>g[i][j];

    std::queue<std::array<int,2>> q;
    std::vector<int> dx={1,0,-1,0},dy={0,-1,0,1};

    auto check=[&](int i,int j){
        int cnt=0;
        for(int k=0;k<4;k++){
            int nx=i+dx[k],ny=j+dy[k];
            if(nx<1 or nx>n or ny<1 or ny>m) continue;
            cnt+=g[nx][ny]=='.';
        }
        return cnt==1;
    };

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(check(i,j)) q.push({i,j});
        }
    }

    while(q.size()){
        auto [x,y]=q.front();
        q.pop();
        if(g[x][y]!='.') continue;
        int sx=-1,sy=-1;
        if(g[x+1][y]=='.'){
            g[x][y]='^';
            g[x+1][y]='v';
            sx=x+1,sy=y;
        }else if(g[x][y+1]=='.'){
            g[x][y]='<';
            g[x][y+1]='>';
            sx=x,sy=y+1;
        }else if(g[x-1][y]=='.'){
            g[x-1][y]='^';
            g[x][y]='v';
            sx=x-1,sy=y;
        }else if(g[x][y-1]=='.'){
            g[x][y-1]='<';
            g[x][y]='>';
            sx=x,sy=y-1;
        }
        for(int i=0;i<4;i++){
            int nx=sx+dx[i],ny=sy+dy[i];
            if(check(nx,ny)) q.push({nx,ny});
        }
    }
    bool flag=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) if(g[i][j]=='.') flag=0;
    if(flag){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++) std::cout<<g[i][j];
            std::cout<<"\n";
        }
    }else std::cout<<"Not unique"<<"\n";

}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
