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
    int sx,sy,ex,ey;
    std::cin>>sx>>sy>>ex>>ey;
    int v,t;
    std::cin>>v>>t;
    int vx,vy,wx,wy;
    std::cin>>vx>>vy>>wx>>wy;

    auto check=[&](double x){
        double tx=(x>t ? sx+vx*t+wx*(x-t) : sx+vx*x);
        double ty=(x>t ? sy+vy*t+wy*(x-t) : sy+vy*x);
        double dx=tx-ex;
        double dy=ty-ey;
        double len=sqrt(dx*dx+dy*dy);
        return len<v*x;
    };

    double l=0,r=10000000000.0;
    for(int i=0;i<=100;i++){
        double mid=(l+r)/2.0;
        if(check(mid)) r=mid;
        else l=mid;
    }
    std::cout<<std::fixed<<std::setprecision(25)<<l<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
