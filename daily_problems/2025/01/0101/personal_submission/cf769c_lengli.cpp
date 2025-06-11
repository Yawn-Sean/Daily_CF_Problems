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
    int n,m,k;
    std::cin>>n>>m>>k;
    if(k&1){
        std::cout<<"IMPOSSIBLE"<<"\n";
        return;
    }

    std::vector<std::vector<char>> g(n,std::vector<char>(m));
    std::vector<int> dx={1,0,0,-1},dy={0,-1,1,0};
    int sx=-1,sy=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            std::cin>>g[i][j];
            if(g[i][j]=='X') sx=i,sy=j;
        }
    }

    bool flag=0;

    for(int i=0;i<4;i++){
        int nx=sx+dx[i],ny=sy+dy[i];
        if(nx<0 or nx>=n or ny<0 or ny>=m) continue;
        if(g[nx][ny]!='*') flag=1;
    }

    if(!flag){
        std::cout<<"IMPOSSIBLE"<<"\n";
        return;
    }

    std::vector<std::vector<int>> d(n,std::vector<int>(m,-1));
    std::queue<std::array<int,3>> q;
    q.push({0,sx,sy});
    while(q.size()){
        auto [v,x,y]=q.front();
        q.pop();
        if(d[x][y]!=-1) continue;
        d[x][y]=v;
        for(int i=0;i<4;i++){
            int nx=x+dx[i],ny=y+dy[i];
            if(nx<0 or nx>=n or ny<0 or ny>=m or g[nx][ny]=='*') continue;
            q.push({v+1,nx,ny});
        }
    }

    std::string res="";

    while(k){
        bool hv=0;
        for(int j=0;j<4;j++){
            int nx=sx+dx[j],ny=sy+dy[j];
            if(nx<0 or nx>=n or ny<0 or ny>=m or g[nx][ny]=='*' or d[nx][ny]>k-1) continue;
            res+=(j==0 ? "D" : j==1 ? "L" : j==2 ? "R" : "U");
            sx=nx,sy=ny;
            hv=1;
            break;
        }
        if(hv==0) break;
        k--;
    }
    std::cout<<res<<"\n";

}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
