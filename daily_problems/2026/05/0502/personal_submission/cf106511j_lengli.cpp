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
    int n;
    std::cin>>n;
    std::vector<int> a(n+2),b(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];
    for(int i=1;i<=n;i++) std::cin>>b[i];
    
    auto check=[&](std::vector<int> x)->std::vector<int>{
        std::vector<int> st(n+2);
        std::vector<int> res;
        auto dfs=[&](auto self,int u)->int{
            if(st[u]) return 0;
            st[u]=1;
            return self(self,x[u])+1;
        };
        
        for(int i=1;i<=n;i++){
            if(st[i]) continue;
            res.pb(dfs(dfs,i));
        }
        std::sort(all(res));
        res.erase(unique(all(res)),res.end());
        return res;
    };
    
    std::vector<int> pa=check(a);
    std::vector<int> pb=check(b);
    i64 res=0;
    
    for(auto x:pa){
        i64 ans=4e18;
        for(auto y:pb){
            ans=std::min(ans,std::lcm(1ll*x,1ll*y));
        }
        res=std::max(res,ans);
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
