/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int inf=1e9;

void solve(){
    int n,m,k;
    std::cin>>n>>m>>k;
    std::vector<int> a(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];
    if(n%2==0){
        std::cout<<0<<"\n";
        return;
    }
    int t=inf;
    for(int i=1;i<=n;i+=2){
        t=std::min(t,a[i]);
    }
    i64 res=std::min(1ll*t,1ll*(m/((n+1)/2))*k);
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
