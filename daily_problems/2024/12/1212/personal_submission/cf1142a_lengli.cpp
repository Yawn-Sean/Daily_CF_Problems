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
    i64 n,k,a,b;
    std::cin>>n>>k>>a>>b;
    std::vector<int> tmp={a+b,a-b,b-a,-a-b};
    i64 p=n*k;
    i64 mx=-1,mi=1e18;

    for(int i=0;i<4;i++){
        i64 s=tmp[i];
        for(int j=0;j<n;j++){
            i64 v=std::abs(std::gcd(p,s));
            mx=std::max(mx,p/v);
            mi=std::min(mi,p/v);
            s+=k;
        }
    }
    std::cout<<mi<<" "<<mx<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
