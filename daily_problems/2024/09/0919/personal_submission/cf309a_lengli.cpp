/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n,l,t;
    std::cin>>n>>l>>t;
    std::vector<int> a(n*2);
    for(int i=0;i<n;i++){
        std::cin>>a[i];
        a[i+n]=a[i]+l;
    }
    int k=2*t/l,p=2*t%l;
    double res=(double)k*n*(n-1);
    for(int i=0,j=0;i<n;i++){
        while(j<2*n and a[j]-a[i]<=p) j++;
        res+=j-i-1;
    }
    std::cout<<std::fixed<<std::setprecision(10)<<res/4.0<<"\n";

}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
