/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

using i64=long long;
using i128=__int128;

void solve(){
    i64 n;
    std::cin>>n;
    std::vector<std::array<i64,2>> res,ans;
    for(int i=1;i<=2000000;i++){
        i64 l=6ll*n+1ll*i*i*i-i;
        i64 r=3ll*i*i+3ll*i;
        if(!r or l%r) continue;
        i64 m=l/r;
        if(i>m) break;
        res.pb({(i64)i,m});
        ans.pb({m,(i64)i});
    }
    res.insert(res.end(),all(ans));
    sort(all(res));
    res.erase(unique(all(res)),res.end());
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
