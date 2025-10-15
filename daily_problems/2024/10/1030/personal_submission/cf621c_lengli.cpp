/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

#define i128 __int128

void solve(){
    int n,p;
    std::cin>>n>>p;
    std::vector<std::array<int,2>> a(n);
    for(auto &[l,r]:a) std::cin>>l>>r;
    auto get=[&](int l,int r){
        return r/p-(l-1)/p;
    };
    long double res=0;
    for(int i=0;i<n;i++){
        auto l=(i-1+n)%n,r=(i+1)%n;
        i128 la=a[l][1]-a[l][0]+1;
        i128 lb=a[i][1]-a[i][0]+1;
        i128 cnta=get(a[l][0],a[l][1]);
        i128 cntb=get(a[i][0],a[i][1]);
        i128 fm=(i128)la*(i128)lb;
        i128 fz=(cnta)*(lb-cntb)+(cntb)*(la-cnta)+cntb*cnta;
        res+=2000.0*(long double)fz/fm;
    }
    std::cout<<std::fixed<<std::setprecision(10)<<res;
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
