/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

constexpr long long inf=1e18;

#define int long long

void solve(){
    int n;
    std::cin>>n;
    std::vector<int> a(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];
    std::vector<int> suf(n+2,inf),pre(n+2,inf);
    std::vector<int> suf_mx(n+2,inf),pre_mx(n+2,inf);
    suf[0]=0,pre[0]=0;suf_mx[0]=0,pre_mx[0]=0;
    
    auto get=[&](std::vector<int> &f,std::vector<int> &mx){
        for(int i=1;i<=n;i++){
            if(a[i]>mx[i-1]) f[i]=f[i-1],mx[i]=a[i];
            else{
                mx[i]=mx[i-1]+1;
                f[i]=f[i-1]+mx[i]-a[i];
            }   
        }
    };

    get(pre,pre_mx);
    reverse(all(a));
    get(suf,suf_mx);
    reverse(all(suf)),reverse(all(suf_mx));

    long long res=suf[1];
    for(int i=1;i<=n;i++){
        int l=pre_mx[i],r=suf_mx[i+1];
        int ans=0;
        if(l<=r) ans+=r-l+1;
        ans+=pre[i]+suf[i+1];
        res=std::min(res,ans);
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
