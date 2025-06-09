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
    int n;
    std::cin>>n;
    std::vector<int> a(n+2);
    int mx=0;
    i64 sum=0;
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
        sum+=a[i];
        mx=std::max(a[i],mx);
    }
    if((sum-mx)*2<mx) std::cout<<sum-mx<<"\n";
    else std::cout<<sum/3<<"\n";

}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
