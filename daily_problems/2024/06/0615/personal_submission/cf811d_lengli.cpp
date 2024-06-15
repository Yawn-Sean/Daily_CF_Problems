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
    std::vector<std::vector<char>> g(n+1,std::vector<char> (m+1));
    int ex=-1,ey=-1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) {
            std::cin>>g[i][j];
            if(g[i][j]=='F') ex=i,ey=j;
        }
    std::vector<std::array<int,2>> path;
    auto bfs=[&](){
        std::queue<std::array<int,2>> q;
        std::vector<std::vector<int>> st(n+1,std::vector<int> (m+1,0));
        std::vector<std::vector<std::array<int,2>>> fa(n+1,std::vector<std::array<int,2>> (m+1));
        std::vector<int> dx={1,0,-1,0},dy={0,-1,0,1};
        q.push({1,1});
        while(q.size()){
            auto [xx,yy]=q.front();
            q.pop();
            if(st[xx][yy]) continue;
            st[xx][yy]=1;
            for(int j=0;j<4;j++){
                int nx=xx+dx[j],ny=yy+dy[j];
                if(nx<1 or nx>n or ny<1 or ny>m or g[nx][ny]=='*') continue;
                if(st[nx][ny]) continue;
                fa[nx][ny]={xx,yy};
                q.push({nx,ny});
            }
        }
        int xx=ex,yy=ey;
        while(xx!=1 or yy!=1){
            path.pb({xx,yy});
            auto [nx,ny]=fa[xx][yy];
            xx=nx,yy=ny;
        }
    };
    
    bfs();
    reverse(all(path));

    auto query=[&](char c)->std::array<int,2>{
        std::cout<<c<<std::endl;
        int x,y;
        std::cin>>x>>y;
        return {x,y};
    };
    std::map<char,char> fx;
    int sx=1,sy=1;
    for(auto [x,y]:path) {
        char nd;
        if(x==sx and y>sy) nd='R';
        else if(x==sx and y<sy) nd='L';
        else if(x>sx) nd='D';
        else nd='U';
        if(fx.count(nd)) {
            auto [nx,ny]=query(fx[nd]);
            sx=nx,sy=ny;
        }else{
            if(nd=='D'){
                auto [nx,ny]=query(nd);
                if(nx==sx and ny==sy) {
                    fx['D']='U',fx['U']='D';
                    auto [nx,ny]=query(fx[nd]);
                    sx=nx,sy=ny;
                }else{
                    fx['D']='D',fx['U']='U'; 
                    sx=nx,sy=ny;
                }
            }else{
                auto [nx,ny]=query(nd);
                if(nx==sx and ny==sy) {
                    fx['R']='L',fx['L']='R';
                    auto [nx,ny]=query(fx[nd]);
                    sx=nx,sy=ny;
                }else{
                    fx['R']='R',fx['L']='L'; 
                    sx=nx,sy=ny;
                }
            }
        }
        assert(sx==x and sy==y);
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
