/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int inf=1e9;

void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<std::vector<char>> g(n+2,std::vector<char> (m+2));
    int ma_1=-inf,mi_1=inf,ma_2=-inf,mi_2=inf;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            std::cin>>g[i][j];
            if(g[i][j]=='B'){
                ma_1=std::max(ma_1,i+j);
                mi_1=std::min(mi_1,i+j);
                ma_2=std::max(ma_2,i-j);
                mi_2=std::min(mi_2,i-j);
            }
        }
    }

    int res=inf;
    int x=-1,y=-1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int d=ma_1-i-j;
            d=std::max(d,i+j-mi_1);
            d=std::max(d,ma_2-i+j);
            d=std::max(d,i-j-mi_2);
            if(d<res) std::tie(res,x,y)=std::tie(d,i,j);
        }
    }
    std::cout<<x<<" "<<y<<"\n";
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
