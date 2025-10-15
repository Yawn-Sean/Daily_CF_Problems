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
    int n,m;
    std::cin>>n>>m;
    std::vector<int> a(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];
    int idx=(n+1)/2;
    i64 res=0;
    for(int i=n;i>=idx;i-=m) res+=a[i]-a[idx];
    for(int i=1;i<idx;i+=m) res+=a[idx]-a[i];
    std::cout<<res*2<<"\n";
    

}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
