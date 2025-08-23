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
    std::vector<std::array<int,2>> pt(m);
    for(auto &[d,h]:pt) std::cin>>d>>h;

    int la_d=-1,la_h=-1;
    int res=pt[0][1]+pt[0][0]-1;

    for(auto [d,h]:pt){
        if(la_d==-1){
            la_d=d;
            la_h=h;
            continue;
        }
        bool flag=1;

        if(std::abs(d-la_d)<std::abs(h-la_h)){
            std::cout<<"IMPOSSIBLE"<<"\n";
            return;
        }
        int ans=(la_h+h+d-la_d)/2;
        res=std::max(res,ans);
        la_d=d,la_h=h;
    }
    res=std::max(res,la_h+n-la_d);
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
