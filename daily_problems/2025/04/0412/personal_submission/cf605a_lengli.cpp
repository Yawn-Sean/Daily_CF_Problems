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
    int n;
    std::cin>>n;
    std::vector<int> a(n);
    for(auto &x:a) std::cin>>x;
    std::vector<int> f(n+2,0);
    int mx=0;
    for(auto x:a){
        if(x==1) f[x]=1;
        else f[x]=f[x-1]+1;
        mx=std::max(mx,f[x]);
    }
    
    std::cout<<n-mx<<'\n';
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
