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
    int n,m;
    std::cin>>n>>m;
    std::vector<int> a(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];

    auto check=[&](int x){
        std::vector<int> f(n+2,0);
        for(int i=1;i<=n;i++){
            f[i]=1;
            for(int j=1;j<i;j++){
                if(std::abs(a[i]-a[j])<=1ll*(i-j)*x){
                    f[i]=std::max(f[i],f[j]+1);
                }
            }
            if(f[i]+m>=n) return 1;
        }
        return 0;
    };

    int l=0,r=2e9;
    while(l<r){
        int mid=(l+r)>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    std::cout<<r;
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
