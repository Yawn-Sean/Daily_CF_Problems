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
    std::vector<std::array<int,2>> res;
    int l=1,r=2;
    while(res.size()<n and l<=k and r<=k){
        res.pb({l,r});
        if(res.size()<n) res.pb({r,l});
        r++;
        if(r>k) l++,r=l+1;
    }
    if(res.size()<n) std::cout<<"NO"<<"\n";
    else{
        std::cout<<"YES"<<"\n";
        for(auto [l,r]:res) std::cout<<l<<" "<<r<<"\n";
    }

}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
