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
    int n,w,b;
    std::cin>>n>>w>>b;

    combine tr(w+b+2,1000000009);

    Mint res=Mint(tr.aa[w])*Mint(tr.aa[b])*(w-1)*tr.C(w+b-3,n-3);
    std::cout<<res<<"\n";

}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
