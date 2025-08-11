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
    std::vector<int> a(n+2),pos(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i],pos[a[i]]=i;

    std::vector<int> mx(n+2,-1);

    for(int i=1;i<=m;i++){
        int u,v;
        std::cin>>u>>v;
        int l=pos[u],r=pos[v];
        if(l>r) std::swap(l,r);
        mx[r]=std::max(mx[r],l);
    }

    i64 res=0;

    for(int l=1,r=1;l<=n;l++){
        while(r<=n and mx[r]<l) r++;
        res+=r-l;
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
