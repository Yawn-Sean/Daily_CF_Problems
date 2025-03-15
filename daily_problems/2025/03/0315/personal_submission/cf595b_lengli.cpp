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
    std::vector<int> p(12,1);
    for(int i=1;i<=9;i++) p[i]=p[i-1]*10;

    int n,k;
    std::cin>>n>>k;
    int m=n/k;
    std::vector<int> a(m+2),b(m+2);
    for(int i=1;i<=m;i++) std::cin>>a[i];
    for(int i=1;i<=m;i++) std::cin>>b[i];

    i64 res=1;
    for(int i=1;i<=m;i++){
        i64 r1=(p[k]-1)/a[i]+1;
        i64 r2=(1ll*p[k-1]*(b[i]+1)-1)/a[i]+1;
        i64 r3=(1ll*p[k-1]*b[i]-1)/a[i]+1;
        if(!b[i]) r3=0;
        res*=r1-r2+r3;
        res%=1000000007;
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
