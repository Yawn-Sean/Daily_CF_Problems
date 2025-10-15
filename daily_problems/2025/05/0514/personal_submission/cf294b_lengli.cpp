/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

int f[110][20010];

constexpr int inf=1e9;

void solve(){
    int n;
    std::cin>>n;
    std::vector<std::array<int,2>> q(n+2);
    for(int i=1;i<=n;i++) std::cin>>q[i][0]>>q[i][1];

    for(int i=0;i<=n;i++)
        for(int j=0;j<20010;j++) f[i][j]=inf;

    int dx=10000;
    f[0][0]=0;

    for(int i=0;i<n;i++){
        auto [a,b]=q[i+1];
        for(int j=0;j<20010;j++){
            if(f[i][j]!=inf){
                f[i+1][j+a]=std::min(f[i+1][j+a],f[i][j]);
                f[i+1][j]=std::min(f[i+1][j],f[i][j]+b);
                
            }
        }
    }



    int res=inf;
    for(int j=0;j<20010;j++){
        if(f[n][j]<=j) res=std::min(j,res);
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
