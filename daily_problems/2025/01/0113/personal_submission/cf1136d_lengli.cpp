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
    std::vector<int> a(n+2),id(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i],id[a[i]]=i;

    std::vector<std::set<int>> eg(n+2);

    std::vector<int> q;

    for(int i=1;i<=m;i++){
        int u,v;
        std::cin>>u>>v;
        eg[u].insert(v);
        if(v==a[n]) q.pb(u);
    }

    sort(all(q),[&](auto l,auto r){
        return id[l]>id[r];
    });

    int v=a[n];

    for(auto x:q){
        int idx=id[x];
        while(idx+1<=n and eg[a[idx]].count(a[idx+1])){
            int l=a[idx],r=a[idx+1];
            std::swap(id[l],id[r]);
            std::swap(a[idx],a[idx+1]);
            idx++;
        }
    }

    for(int i=n;i>=1;i--){
        if(a[i]==v){
            std::cout<<n-i<<"\n";
            return;
        }
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
