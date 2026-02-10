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
    std::vector<std::array<int,2>> pt(n);
    for(auto &[x,y]:pt) std::cin>>x>>y;

    auto dist=[&](int u,int v)->i64{
        int dx=pt[u][0]-pt[v][0];
        int dy=pt[u][1]-pt[v][1];
        i64 res=1ll*dx*dx+1ll*dy*dy;
        return res;
    };
    int s=0;
    for(int i=0;i<n;i++){
        if(dist(0,s)<dist(0,i)) s=i; 
    }

    auto t=pt[s];

    std::sort(all(pt),[&](auto l,auto r){
        int dx=l[0]-t[0];
        int dy=l[1]-t[1];
        int ddx=r[0]-t[0];
        int ddy=r[1]-t[1];
        return 1ll*dx*dx+1ll*dy*dy<1ll*ddx*ddx+1ll*ddy*ddy;
    });

    long double res=0;

    for(int i=1;i<n;i++){
        res+=sqrtl(dist(i-1,i));
    }
    std::cout<<std::fixed<<std::setprecision(10)<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
