/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

#define int long long
#define double long double

void solve(){
    std::vector<std::array<int,2>> a(3);
    for(int i=0;i<3;i++) std::cin>>a[i][0]>>a[i][1];
    double res=0;
    int n;
    std::cin>>n;
    std::vector<std::array<int,2>> b(n);

    auto get_dist=[&](std::array<int,2> l,std::array<int,2> r)->double{
        double dx=l[0]-r[0],dy=l[1]-r[1];
        double res=dx*dx+dy*dy;
        return sqrtl(res);
    };
    std::vector<std::array<double,2>> aa,bb;
    for(int i=0;i<n;i++) {
        auto &t=b[i];
        std::cin>>t[0]>>t[1];
        double len=get_dist(t,a[2]);
        res+=len*2.0;
        double l=get_dist(t,a[0]),r=get_dist(t,a[1]);
        aa.pb({len-l,i});
        bb.pb({len-r,i});
    }
    sort(all(aa),std::greater<>());
    sort(all(bb),std::greater<>());

    if(aa[0][0]>=0 and bb[0][0]>=0){
        if(aa[0][1]!=bb[0][1]){
            if(aa[0][0]>0) res-=aa[0][0];
            if(bb[0][0]>0) res-=bb[0][0];
        }else{
            double tt=res;
            {
                double ans=res;
                if(aa[0][0]>0) ans-=aa[0][0];
                if(bb.size()>=2 and bb[1][0]>0) ans-=bb[1][0];
                tt=std::min(tt,ans);
            }
            {
                double ans=res;
                if(bb[0][0]>0) ans-=bb[0][0];
                if(aa.size()>=2 and aa[1][0]>0) ans-=aa[1][0];
                tt=std::min(tt,ans);
            }
            res=tt;
        }
    }else{
        if(aa[0][0]>bb[0][0]) res-=aa[0][0];
        else res-=bb[0][0];
    }

    std::cout<<std::fixed<<std::setprecision(12)<<res<<"\n";
    
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
