/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

constexpr int inf=2e9+1;

void solve(){
    int n;
    std::cin>>n;
    std::vector<int> a(n+2,0),b(n+2,0);
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
        b[i]=b[i-1]+a[i];
    }
    
    std::vector<int> f(n+2,-inf);
    f[n-1]=b[n];
    for(int i=n-2;i>=1;i--){
        f[i]=std::max(f[i+1],b[i+1]-f[i+1]);
    }
    std::cout<<f[1]<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
