/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n;
    std::cin>>n;
    std::vector<int> a(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];
    int res=0;
    for(int i=1;i<=n;i++){
        int l=i,r=i;
        while(r+1<=n and a[r+1]!=a[r]) r++;
        res=std::max(res,(r-l)/2);
        int mid=(r+l)/2;
        for(int j=l;j<=mid;j++) a[j]=a[l];
        for(int j=mid+1;j<=r;j++) a[j]=a[r];
        i=r;
    }
    std::cout<<res<<"\n";
    for(int i=1;i<=n;i++) std::cout<<a[i]<<" ";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
