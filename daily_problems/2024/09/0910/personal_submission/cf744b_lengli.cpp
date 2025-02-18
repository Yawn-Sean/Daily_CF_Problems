/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n;
    std::cin>>n;
    auto query=[&](std::vector<int> &qr){
        std::cout<<qr.size()<<"\n";
        for(auto x:qr) std::cout<<x<<" ";
        std::cout<<std::endl;
        std::vector<int> res(n);
        for(auto &x:res) std::cin>>x;
        return res;
    };
    auto print=[&](std::vector<int> &res){
        std::cout<<"-1"<<"\n";
        for(auto x:res) std::cout<<x<<" ";
        std::cout<<std::endl;
    };
    std::vector<int> res(n,1e9);
    for(int j=0;j<10;j++){
        std::vector<int> l,r;
        for(int i=1;i<=n;i++){
            if(i>>j&1) l.pb(i);
            else r.pb(i);
        }
        if(l.size()==0 or r.size()==0) break;
        l=query(l),r=query(r);
        for(int i=1;i<=n;i++){
            if(i>>j&1) res[i-1]=std::min(res[i-1],r[i-1]);
            else res[i-1]=std::min(res[i-1],l[i-1]);
        }
    }
    print(res);
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
