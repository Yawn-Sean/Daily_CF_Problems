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
    std::vector<i64> a(3);
    for(auto &x:a) std::cin>>x;
    sort(all(a));
    if((a[1]-a[0]&1)==0) std::cout<<a[1]<<"\n";
    else std::cout<<a[2]<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
