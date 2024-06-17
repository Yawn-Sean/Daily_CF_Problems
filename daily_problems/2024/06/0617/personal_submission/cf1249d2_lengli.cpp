/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n,k;
    std::cin>>n>>k;
    std::vector<std::array<int,2>> q(n+2);
    std::vector<std::vector<int>> eg(200010);
    for(int i=1;i<=n;i++) {
        std::cin>>q[i][0]>>q[i][1];
        eg[q[i][0]].pb(i);
    }
    std::set<std::array<int,2>> s;
    std::vector<int> res;
    for(int i=1;i<=200000;i++){
        for(auto id:eg[i]) s.insert({q[id][1],id});
        while(s.size()){
            auto it=*s.begin();
            if(it[0]<i) s.erase(it);
            else break;
        }
        while(s.size()>k){
            auto it=*s.rbegin();
            res.pb(it[1]);
            s.erase(it);
        }
    }
    std::cout<<res.size()<<"\n";
    for(auto x:res) std::cout<<x<<" ";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
