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
    int a,b,m;
    std::cin>>a>>b>>m;
    int vx,vy,vz;
    std::cin>>vx>>vy>>vz;
    double time=(double)m/std::abs(vy);
    double x=(double)a/2.0+time*vx;
    int d=x/(2*a);
    x-=d*(2*a);
    if(x<0) x+=2*a;
    if(x>a) x=2*a-x;

    double z=time*vz;
    d=z/(2*b);
    z=z-d*(2*b);
    if(z<0) z+=2*b;
    if(z>b) z=2*b-z;
    std::cout<<std::fixed<<std::setprecision(10)<<x<<" "<<z<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
