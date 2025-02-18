/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long
#define f64 double

constexpr i64 inf=1e18;

void solve(){
    int n,m,a,b;
    std::cin>>n>>m>>a>>b;
    std::vector<int> ya(n),yb(m);
    for(auto &x:ya) std::cin>>x;
    for(auto &x:yb) std::cin>>x;
    std::vector<int> len(m);
    for(auto &x:len) std::cin>>x;

    f64 mi=inf;
    int resa=-1,resb=-1;

    auto get_dist=[&](std::array<int,2> &l,std::array<int,2> &r){
        f64 dx=l[0]-r[0],dy=l[1]-r[1];
        return std::sqrt(dx*dx+dy*dy);
    };

    for(int i=0;i<m;i++){
        int l=0,r=n-1;

        auto check=[&](int id)->f64{
            std::array<int,2> t={a,ya[id]};
            std::array<int,2> tt={b,yb[i]};
            std::array<int,2> o={0,0};
            return get_dist(o,t)+get_dist(t,tt);
        };

        while(l<r){
            int midl=l+(r-l)/3;
            int midr=r-(r-l)/3;
            if(check(midl)<=check(midr)) r=midr-1;
            else l=midl+1;
        }

        f64 ans=check(l)+len[i];
        if(ans<mi){
            mi=ans;
            resa=l+1,resb=i+1;
        }
        ans=check(r)+len[i];
        if(ans<mi){
            mi=ans;
            resa=r+1,resb=i+1;
        }
    }
    std::cout<<resa<<" "<<resb<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
