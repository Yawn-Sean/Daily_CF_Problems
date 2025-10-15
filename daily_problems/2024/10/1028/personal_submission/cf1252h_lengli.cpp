/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

#define int long long

void solve(){
    int n;
    std::cin>>n;
    std::vector<std::array<int,2>> a(n);
    long long res=0;
    for(int i=0;i<n;i++){
        auto &[x,y]=a[i];
        std::cin>>x>>y;
        res=std::max(res,1ll*x*y);
        if(x<y) std::swap(x,y);
    }
    sort(all(a));
    reverse(all(a));
    int la=0;
    for(auto [x,y]:a){
        res=std::max(res,x*std::min(y,la)*2ll);
        la=std::max(la,y);
    }
    std::cout<<(res/2)<<"."<<(res&1 ? 5 : 0)<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
