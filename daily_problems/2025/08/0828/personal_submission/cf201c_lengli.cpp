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
    std::vector<int> a(n+2);
    for(int i=1;i<n;i++) std::cin>>a[i];
    std::vector<i64> l(n+2),r(n+2);
    for(int i=2;i<=n;i++) l[i]=a[i-1]/2==0 ? 0 : l[i-1]+a[i-1]/2*2;
    for(int i=n-1;i>=1;i--) r[i]=a[i]/2==0 ? 0 : r[i+1]+a[i]/2*2;
    std::vector<i64> pre(n+2);
    for(int i=2;i<=n;i++){
        int v=a[i-1]&1 ? a[i-1] : a[i-1]-1;
        pre[i]=pre[i-1]+v;
    }
    i64 ans=0;
    i64 mx=0;
    for(int i=n;i>=1;i--){
        mx=std::max(mx,r[i]+pre[i]);
        ans=std::max(ans,l[i]-pre[i]+mx);
    }
    std::cout<<ans<<"\n";
}   

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
