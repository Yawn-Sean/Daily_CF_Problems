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
    std::vector<int> a(n);
    for(auto &x:a) std::cin>>x;
    std::sort(all(a));
    while(k--){
        int op;
        std::cin>>op;
        if(op==1){
            int x;
            std::cin>>x;
            if(x>a.back()) a.pb(x);
            else{
                auto it=std::upper_bound(all(a),x)-a.begin();
                if(it and a[it-1]==x) continue;
                else a[it]=x;
            }
        }else{
            int l,r;
            std::cin>>l>>r;
            auto res=std::upper_bound(all(a),r)-std::lower_bound(all(a),l);
            std::cout<<res<<"\n";
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
