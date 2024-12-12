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
    int n,k;
    std::cin>>n>>k;

    std::vector<int> a(n+2);

    i64 sum=0;
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
        sum+=a[i];
    }
    i64 avg=sum/n;

    auto get_max=[&](){
        auto check=[&](int x){
            i64 cnt=0;
            for(int i=1;i<=n;i++){
                if(a[i]>x) cnt+=a[i]-x;
            }
            return cnt<=k;
        };

        i64 l=avg+(sum%n!=0),r=inf;
        while(l<r){
            i64 mid=(l+r)/2;
            if(check(mid)) r=mid;
            else l=mid+1;
        }
        return r;
    };

    auto get_min=[&](){
        auto check=[&](int x){
            i64 cnt=0;
            for(int i=1;i<=n;i++){
                if(a[i]<x) cnt+=x-a[i];
            }
            return cnt<=k;
        };

        i64 l=0,r=avg;
        while(l<r){
            i64 mid=(l+r+1)/2;
            if(check(mid)) l=mid;
            else r=mid-1;
        }
        return l;
    };

    std::cout<<get_max()-get_min()<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
