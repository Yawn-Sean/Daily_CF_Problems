/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

constexpr int inf=1e9;

void solve(){
    int n,k;
    std::cin>>n>>k;
    std::vector<std::vector<char>> g(n+2,std::vector<char> (n+2));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) std::cin>>g[i][j];
    std::vector<std::vector<int>> f(n+2,std::vector<int> (n+2,inf));
    f[0][1]=f[1][0]=0;
    int len=0;
    std::vector<std::array<int,2>> pt;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int v=(g[i][j]=='a' ? 0 : 1);
            f[i][j]=std::min(f[i-1][j]+v,f[i][j]);
            f[i][j]=std::min(f[i][j-1]+v,f[i][j]);
            if(f[i][j]<=k){
                if(i+j-1>len){
                    len=i+j-1;
                    pt.clear();
                    pt.pb({i,j});
                }else if(i+j-1==len) pt.pb({i,j});
            }
        }
    }
    std::vector<std::vector<int>> st(n+2,std::vector<int> (n+2,0));
    std::string res=std::string(len,'a');
    if(pt.empty()){
        res+=g[1][1];
        pt.pb({1,1});
    }
    while((int)res.size()<n*2-1){
        char mx='z';
        std::vector<std::array<int,2>> q;
        for(auto [x,y]:pt){
            std::vector<int> dx={1,0},dy={0,1};
            for(int i=0;i<2;i++){
                int nx=x+dx[i],ny=y+dy[i];
                if(nx<=n and ny<=n and !st[nx][ny]){
                    if(g[nx][ny]==mx) q.pb({nx,ny});
                    else if(g[nx][ny]<mx){
                        q.clear();
                        mx=g[nx][ny];
                        q.pb({nx,ny});
                    }
                    st[nx][ny]=1;
                }
            }
        }
        pt.swap(q);
        res+=mx;
    }
    std::cout<<res;

}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
