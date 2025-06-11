/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n,m;
    std::cin>>n>>m;
    int ans=1e9;
    for(int i=1;i<=m;i++){
        int l,r;
        std::cin>>l>>r;
        ans=std::min(ans,r-l+1);
    }
    std::cout<<ans<<"\n";
    for(int i=1,j=0;i<=n;i++,j++,j%=ans){
        std::cout<<j<<" ";
    }
}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
