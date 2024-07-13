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
    std::vector<int> res;
    int k=1,b=n;
    while(b){
        if(b==3){
            res.pb(k);
            res.pb(k);
            res.pb(3*k);
            b=0;
            break;
        }
        int cnt=b-b/2;
        for(int i=1;i<=cnt;i++) res.pb(k);
        k*=2;
        b/=2;
        if(b==3){
            res.pb(k);
            res.pb(k);
            res.pb(3*k);
            b=0;
        }
    }
    for(auto x:res) std::cout<<x<<" ";
    
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
