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
    int n,k;
    std::cin>>n>>k;

    if(n==1){
        std::cout<<0<<"\n";
        return; 
    }

    std::vector<int> d(n+2);

    int root=-1;

    std::vector<std::vector<int>> q(n+2);
    for(int i=1;i<=n;i++){
        std::cin>>d[i];
        if(!d[i]) root=i;
        q[d[i]].pb(i);
    }
    if(root==-1 or q[0].size()>1){
        std::cout<<"-1"<<"\n";
        return;
    }
    std::vector<int> rd(n+2);
    std::vector<std::array<int,2>> res;

    for(int i=1;i<=n;i++){
        for(auto x:q[i]){
            while(q[i-1].size()){
                auto t=q[i-1].back();
                if(rd[t]>=k) q[i-1].pop_back();
                else break;
            }
            if(q[i-1].empty()){
                std::cout<<"-1"<<"\n";
                return;
            }
            auto t=q[i-1].back();
            rd[x]++;
            rd[t]++;
            res.pb({t,x});
        }
    }
    for(int i=1;i<=n;i++){
        if(rd[i]>k){
            std::cout<<"-1"<<"\n";
            return;
        }
    }
    std::cout<<res.size()<<"\n";
    for(auto [l,r]:res) std::cout<<l<<" "<<r<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
