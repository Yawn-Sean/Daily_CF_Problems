/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n,m,q;
    std::cin>>n>>m>>q;
    std::vector<int> w(n);
    for(auto &x:w) std::cin>>x;
    std::vector<int> cnt(1<<n);
    auto get=[&](std::string s){
        int res=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1') res+=(1<<i);
        }
        return res;
    };
    for(int i=1;i<=m;i++){
        int x=0;
        std::string s;
        std::cin>>s;
        cnt[get(s)]++;
    }
    std::vector<int> g(1<<n,0);
    for(int i=1;i<(1<<n);i++){
        auto it=(i&-i);
        g[i]+=g[i-it]+w[std::__lg(it)];
    }

    std::vector<std::vector<int>> f(1<<n,std::vector<int> (101,0));
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<(1<<n);j++) {
            int t=0;
            for(int k=0;k<n;k++) if((j>>k&1)==(i>>k&1)) t+=(1<<k);
            if(g[t]<=100) f[i][g[t]]+=cnt[j];
        }
    }
    for(int i=0;i<(1<<n);i++){
        for(int j=1;j<=100;j++) f[i][j]+=f[i][j-1];
    }
    while(q--){
        std::string s;
        int k;
        std::cin>>s>>k;
        std::cout<<f[get(s)][k]<<"\n";
    }
    
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
