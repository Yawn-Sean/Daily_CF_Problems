/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

struct Point{
    int x,y,t;
    double p;
};

void solve(){
    int n;
    std::cin>>n;
    std::vector<Point> a(n);
    for(auto &r:a) std::cin>>r.x>>r.y>>r.t>>r.p;
    std::sort(all(a),[&](auto l,auto r){
        return l.t<r.t;
    });
    std::vector<double> f(n,0);
    f[0]=a[0].p;
    double res=f[0];

    auto check=[&](Point l,Point r)->bool{
        double dx=l.x-r.x,dy=l.y-r.y;
        return std::sqrt(dx*dx+dy*dy)<=std::abs(l.t-r.t);
    };

    for(int i=1;i<n;i++){
        f[i]=a[i].p;
        for(int j=0;j<i;j++){
            if(check(a[i],a[j])){
                f[i]=std::max(f[i],f[j]+a[i].p);
            }
        }
        res=std::max(res,f[i]);
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
