/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

#define double long double

constexpr double pi=acos(-1);

void solve(){
    int n;
    std::cin>>n;
    std::vector<std::array<int,2>> pt(n);
    for(auto &[x,y]:pt) std::cin>>x>>y;

    std::vector<double> a(n);
    for(int i=0;i<n;i++){
        double dlt=atan2l((double)pt[i][1],(double)pt[i][0]);
        if(dlt<0) dlt=2.0*pi+dlt;
        a[i]=dlt;
    }
    sort(all(a));
    double res=0;
    for(int i=1;i<n;i++){
        double ans=(a[i]-a[i-1]);
        res=std::max(res,ans);
    }
    res=std::min(2*pi-res,a.back()-a[0]);
    res=res/pi*180;
    std::cout<<std::fixed<<std::setprecision(10)<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
