/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i128 __int128
#define int long long

void solve(){
    int a,b,n;
    std::cin>>a>>b>>n;
    auto get=[&](int x)->long long{
        return 1ll*(x-1)*b+a;
    };
    while(n--){
        int idx,t,m;
        std::cin>>idx>>t>>m;
        long long l=idx,r=1e7;

        auto check=[&](int x){
            if(get(x)>t) return 0;
            i128 sum=(i128)(x-idx+1)*((i128)get(idx)+(i128)get(x))/2;
            if(sum>m*t) return 0;
            return 1;
        };
        while(l<r){
            long long mid=(l+r+1)>>1;
            if(check(mid)) l=mid;
            else r=mid-1;
        }
        if(check(l) and l>=idx) std::cout<<l<<"\n";
        else std::cout<<"-1"<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
