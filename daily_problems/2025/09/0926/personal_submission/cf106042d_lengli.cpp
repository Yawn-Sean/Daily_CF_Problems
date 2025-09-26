/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr i64 inf=2e18;

void solve(){
    int n,x,y;
    std::cin>>n>>x>>y;
    std::vector<i64> a(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];
    i64 sum=0;
    for(int i=1;i<=n;i++) sum+=a[i];

    i64 mx1=-inf,mx2=-inf;
    int idx=-1;
    for(int i=1;i<=n;i++){
        i64 bj=(a[i]&y)-a[i];
        if(bj>mx1) {
            mx2=mx1;
            mx1=bj;
            idx=i;
        }else if(bj>mx2) mx2=bj;
    }

    i64 mx_d=inf;

    for(int i=1;i<=n;i++){
        i64 ci=(a[i]|x)-a[i];
        i64 di=((a[i]|x)&y)-a[i];
        i64 t=(i!=idx ? mx1 : mx2);
        i64 cur=std::max(di,ci+t);
        mx_d=std::min(mx_d,cur);
    }
    std::cout<<sum+mx_d<<"\n";
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
