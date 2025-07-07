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
    double x_1,y_1,r_1,R_1;
    double x_2,y_2,r_2,R_2;

    std::cin>>x_1>>y_1>>r_1>>R_1;
    std::cin>>x_2>>y_2>>r_2>>R_2;

    auto dist=[&](double a,double b,double c,double d)->double{
        double ans=(a-b)*(a-b)+(c-d)*(c-d);
        return std::sqrt(ans);
    };

    auto in=[&](double d,double l,double r)->bool{
        return d+l<=r;
    };
    auto out=[&](double d,double l,double r)->bool{
        if(d>=l+r) return 1;
        return in(d,r,l);
    };

    double d=dist(x_1,x_2,y_1,y_2);
    int res=0;
    if(in(d,r_1,r_2) or out(d,r_1,R_2)) res++;
    if(in(d,R_1,r_2) or out(d,R_1,R_2)) res++;
    if(in(d,r_2,r_1) or out(d,r_2,R_1)) res++;
    if(in(d,R_2,r_1) or out(d,R_2,R_1)) res++;
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
