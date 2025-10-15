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
    std::vector<i64> a(n+2),b(m+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];
    for(int i=1;i<=m;i++) std::cin>>b[i];
    i64 l=0,r=20000000000;

    auto check=[&](i64 k)->bool{
        int j=1;
        i64 la=b[j];
        for(int i=1;i<=n;i++){
            if(a[i]>la){
                i64 ll=std::max(la,a[i]-k);
                i64 rr=std::max(a[i],ll+k-(a[i]-ll));
                rr=std::max(rr,a[i]+(k-a[i]+la)/2);
                while(j<=m and b[j]>=ll and b[j]<=rr) j++;
            }else{
                i64 rr=a[i]+k;
                while(j<=m and b[j]<=rr) j++;
            }
            if(j>m) return 1;
            la=b[j];
        }
        return 0;
    };

    while(l<r){
        i64 mid=(l+r)/2;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    
    std::cout<<r<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
