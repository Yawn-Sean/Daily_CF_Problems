/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    long long n;
    std::cin>>n;
    std::vector<long long> f(110);
    f[1]=2,f[2]=3;
    for(int i=3;f[i-1]<=n;i++){
        f[i]=f[i-1]+f[i-2];
    }
    int res=0;
    for(int i=1;i<=100;i++){
        if(f[i] and f[i]<=n) res=i;
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
