/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    std::string s;
    std::cin>>s;

    std::vector<std::vector<int>> res;
    int n=s.size();
    std::vector<std::vector<int>> q(2);
    for(int i=1;i<=n;i++){
        if(s[i-1]=='1'){
            if(q[0].empty()){
                std::cout<<"-1"<<"\n";
                return;
            }
            auto t=q[0].back();
            q[0].pop_back();
            res[t].pb(i);
            q[1].pb(t);
        }else {
            if(q[1].empty()) {
                res.pb({i});
                q[0].pb(res.size()-1);
            }else{
                auto t=q[1].back();
                q[1].pop_back();
                res[t].pb(i);
                q[0].pb(t);
            }
        }
    }
    if(q[1].size()){
        std::cout<<"-1"<<"\n";
        return;
    }
    std::cout<<res.size()<<"\n";
    for(auto x:res){
        std::cout<<x.size()<<" ";
        for(auto c:x) std::cout<<c<<" ";
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
