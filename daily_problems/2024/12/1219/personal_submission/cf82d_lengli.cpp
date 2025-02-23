/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int N=1010,inf=2e9;

int n;
int a[N];
int f[N][N];
std::array<int,2> fa[N][N];

void solve(){
    int n;
    std::cin>>n;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++) f[i][j]=inf;
    }
    for(int i=1;i<=n;i++) std::cin>>a[i];

    f[1][1]=std::max(a[2],a[3]);
    f[1][2]=std::max(a[1],a[3]);
    f[1][3]=std::max(a[1],a[2]);

    int turn=(n+1)/2;

    for(int i=2;i<=turn;i++){
        int x=i*2,y=i*2+1;
        for(int j=1;j<x;j++){
            if(f[i][x]>f[i-1][j]+std::max(a[j],a[y])){
                f[i][x]=f[i-1][j]+std::max(a[j],a[y]);
                fa[i][x]={i-1,j};
            }
            if(f[i][y]>f[i-1][j]+std::max(a[j],a[x])){
                f[i][y]=f[i-1][j]+std::max(a[j],a[x]);
                fa[i][y]={i-1,j};
            }
            if(f[i][j]>f[i-1][j]+std::max(a[y],a[x])){
                f[i][j]=f[i-1][j]+std::max(a[y],a[x]);
                fa[i][j]={i-1,j};
            }
        }
    }

    std::vector<std::array<int,2>> res;

    std::cout<<f[turn][n+1]<<"\n";
    for(int i=turn,j=n+1;i>=1;i--){
        int x=i*2,y=i*2+1;
        auto [_,la]=fa[i][j];
        if(i>1){
            if(j==y) res.pb({la,x});
            else if(j==x) res.pb({la,y});
            else res.pb({x,y});
        }else{
            if(j==2) res.pb({1,3});
            else if(j==1) res.pb({2,3});
            else res.pb({1,2});
        }
        j=la;
    }
    reverse(all(res));
    for(auto [x,y]:res){
        if(x>=1 and x<=n) std::cout<<x<<" ";
        if(y>=1 and y<=n) std::cout<<y<<" ";
        std::cout<<"\n";
    }
}
 
signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
