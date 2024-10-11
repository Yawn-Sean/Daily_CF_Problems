/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

#define int long long

void solve(){
    int n;
    std::cin>>n;
    std::vector<int> a(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];
    std::vector<std::vector<std::array<int,2>>> eg(n+2);
    for(int i=2;i<=n;i++){
        int p,w;
        std::cin>>p>>w;
        eg[p].pb({i,w});
    }

    std::multiset<int> s;
    s.insert(0);

    auto get=[&](auto x){
        auto it=s.lower_bound(x);
        it=prev(it);
        if(it==s.end() or (*it)>=x) return 0;
        return 1;
    };

    auto dfs=[&](auto self,int u,int dep)->int{
        int cnt=1;
        auto v=dep-a[u];
        if(get(v)) return 0;
        s.insert(dep);
        for(auto [v,len]:eg[u]){
            cnt+=self(self,v,dep+len);
        }
        s.erase(s.find(dep));
        return cnt;
    };

    auto cnt=dfs(dfs,1,0);
    std::cout<<n-cnt<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
