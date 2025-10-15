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
    int n,m,s,e;
    std::cin>>n>>m>>s>>e;
    int k=s/e;
    std::vector<int> a(n+2),b(m+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];
    for(int i=1;i<=m;i++) std::cin>>b[i];

    std::vector<std::vector<int>> idx(100010);
    for(int i=1;i<=m;i++) idx[b[i]].pb(i);

    std::vector<int> f(k+2,inf);
    f[0]=0;

    int res=0;

    for(int i=1;i<=n;i++){
        for(int j=k;j>=1;j--){
            int v=a[i];
            if(idx[v].empty()) continue;
            int la=f[j-1];
            auto it=std::upper_bound(all(idx[v]),la)-idx[v].begin();
            if(it>=idx[v].size() or idx[v][it]<=la) continue;
            f[j]=std::min(f[j],idx[v][it]);
            i64 val=j*e+i+f[j];
            if(val<=s) res=std::max(res,j);
        }
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
