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

    if(n==1 and m==1){
        std::cout<<1<<"\n";
        return;
    }

    if(n==1){
        if(m<=3){
            std::cout<<"-1"<<"\n";
            return;
        }
        int mxj=m&1 ? m : m-1;
        int mxo=m&1 ? m-1 : m;
        for(int i=mxj;i>=1;i-=2) std::cout<<i<<" ";
        for(int i=mxo;i>=1;i-=2) std::cout<<i<<" ";
        std::cout<<"\n";
        return;
    }

    if(m==1){
        if(n<=3){
            std::cout<<"-1"<<"\n";
            return;
        }
        int mxj=n&1 ? n : n-1;
        int mxo=n&1 ? n-1 : n;
        for(int i=mxj;i>=1;i-=2) std::cout<<i<<"\n";
        for(int i=mxo;i>=1;i-=2) std::cout<<i<<"\n";
        std::cout<<"\n";
        return;
    }

    std::vector<std::vector<int>> g(n+2,std::vector<int> (m+2,0));

    int l=0,r=n*m/2;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if((i+j)&1) l++,g[i][j]=l;
            else r++,g[i][j]=r;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int l=std::abs(g[i][j]-g[i][j+1]);
            int r=std::abs(g[i][j]-g[i+1][j]);
            if(l<=1 and j+1<=m){
                std::cout<<"-1"<<"\n";
                return;
            }
            if(r<=1 and i+1<=n){
                std::cout<<"-1"<<"\n";
                return;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            std::cout<<g[i][j]<<" ";
        }
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
