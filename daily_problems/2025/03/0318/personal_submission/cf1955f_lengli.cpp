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
    std::vector<int> a(4);
    for(auto &x:a) std::cin>>x;
    int res=a[0]/2+a[1]/2+a[2]/2+a[3]/2;
    if(a[0]&1 and a[1]&1 and a[2]&1) res++;
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
