/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n,m,k,r,c;
    std::cin>>n>>m>>k>>r>>c;
    int x1,y1,x2,y2;
    std::cin>>x1>>y1>>x2>>y2;
    if(x1==x2 and y1==y2) std::cout<<Mint(k).pow(1ll*n*m);
    else std::cout<<Mint(k).pow(1ll*n*m-1ll*r*c);
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
