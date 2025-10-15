/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr i64 inf=1e18;


void solve(){
    i64 n,L;
    std::cin>>n>>L;
    std::vector<i64> a;
    for(int i=1;i<=n;i++){
        i64 x;
        std::cin>>x;
        a.pb(x);
    }

    i64 res=inf;

    auto check=[&](int i,int l,int r){
        i64 mi=inf,mx=0;
        mi=std::min(a[i]-a[l],a[l]);
        mi=std::min(mi,a[r]-a[i]);
        mi=std::min(mi,L-a[r]);

        mx=std::max(a[i]-a[l],a[l]);
        mx=std::max(mx,a[r]-a[i]);
        mx=std::max(mx,L-a[r]);
        res=std::min(res,mx-mi);
    };

    int l=0,r=2;
    for(int i=1;i<n-1;i++){
        if(a[i]>L) break;
        if(r==i){
            if(r+1<n) r++;
            else break;
        }
        while(l+1<i and a[l+1]*2<a[i]) l++;
        while(r+1<n and a[r+1]-a[i]<L-a[r+1]) r++;
        for(int dl=0;dl<=2;dl++){
            for(int dr=0;dr<=2;dr++){
                if(l+dr<i and r+dr<n){
                    check(i,l+dl,r+dr);
                }
            }
        }
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
