/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n,T;
    std::cin>>n>>T;

    std::vector<std::array<int,3>> a(n);
    for(int i=0;i<n;i++){
        auto &[u,v,id]=a[i];
        std::cin>>u>>v;
        id=i+1;
    }
    std::vector<int> res;
    int l=0,r=n;
    auto check=[&](int x){
        std::vector<std::array<int,2>> q;
        for(auto c:a) if(c[0]>=x) q.pb({c[1],c[2]});
        sort(all(q));
        std::vector<int> ans;
        int sum=T;
        for(auto [v,id]:q){
            if(sum>=v and ans.size()<x) ans.pb(id),sum-=v;
            else break;
        }
        if(ans.size()==x){
            res=ans;
            return 1;
        }
        return 0;
    };  
    while(l<r){
        int mid=(l+r+1)/2;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    std::cout<<l<<"\n";
    std::cout<<res.size()<<"\n";
    for(auto x:res) std::cout<<x<<" ";
    std::cout<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
