/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

#define int long long

void solve(){
    int n,k,x;
    std::cin>>n>>k>>x;
    std::vector<int> a(n+2),l(n+2),r(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];
    for(int i=1;i<=n;i++) l[i]=a[i]|l[i-1];
    for(int i=n;i>=1;i--) r[i]=a[i]|r[i+1];
    int res=0;
    
    for(int i=1;i<=n;i++){
        int t=a[i];
        for(int j=0;j<k;j++) t*=x;
        int ans=t|l[i-1]|r[i+1];
        res=std::max(res,ans);
    }
    
    std::cout<<res;
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
