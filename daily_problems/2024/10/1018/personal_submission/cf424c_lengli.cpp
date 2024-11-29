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
    std::vector<int> f(n+2);
    for(int i=1;i<=n;i++) f[i]=f[i-1]^i;
    int res=0;

    for(int i=1;i<=n;i++){
        int x;
        std::cin>>x;
        res^=x;
    }
    for(int i=2;i<=n;i++){
        int k=n/i,m=n%i;
        if(k&1) res^=(f[i-1]^f[m]);
        else res^=f[m];
        
    }
    std::cout<<res<<"\n";

}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
