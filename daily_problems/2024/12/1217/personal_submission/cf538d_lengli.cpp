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
    int n;
    std::cin>>n;
    std::vector<std::vector<char>> res(2*n-1,std::vector<char> (2*n-1,'x'));
    std::vector<std::vector<char>> g(n,std::vector<char> (n,'x'));
    std::vector<std::array<int,2>> q,p;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            std::cin>>g[i][j];
            if(g[i][j]=='.') q.pb({i,j});
            if(g[i][j]=='o') p.pb({i,j});
        }
    }
    int sx=n-1,sy=n-1;
    res[sx][sy]='o';

    for(auto [x,y]:q){
        for(auto [tx,ty]:p){
            int dx=x-tx,dy=y-ty;
            res[sx+dx][sy+dy]='.';
        }
    }

    std::vector<std::array<int,2>> d;
    for(int i=0;i<2*n-1;i++)
        for(int j=0;j<2*n-1;j++){
            if(res[i][j]=='x') d.pb({i-sx,j-sy});
        }

    bool flag=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(g[i][j]=='o'){
                for(auto [dx,dy]:d){
                    int nx=i+dx,ny=j+dy;
                    if(nx<0 or nx>=n or ny<0 or ny>=n) continue;
                    if(g[nx][ny]=='.') flag=0;
                    if(g[nx][ny]=='x') g[nx][ny]='c';
                }
            }
        }
    }
    int cnt=0;
    for(auto x:g)
        for(auto y:x) cnt+=y=='x';
    if(!cnt and flag){
        std::cout<<"YES"<<"\n";
        for(auto y:res){
            for(auto x:y) std::cout<<x;
            std::cout<<"\n";
        }
    }else std::cout<<"NO"<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
