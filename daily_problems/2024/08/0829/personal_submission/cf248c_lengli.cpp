/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i128 __int128
#define int long long

void solve(){
    int y1,y2,yw,xb,yb,r;
    std::cin>>y1>>y2>>yw>>xb>>yb>>r;
    y1=2*yw-2*r-y1;
    y2=2*yw-2*r-y2;
    std::swap(y1,y2);
    i128 L=r*r,R=y2-y1-r;
    R*=R;
    L*=(yb-y2+r)*(yb-y2+r)+xb*xb;
    R*=xb*xb;
    if(L>R) std::cout<<"-1"<<"\n";
    else std::cout<<std::fixed<<std::setprecision(10)<<(double)(y2-yw)*xb/(double)(y2-r-yb);
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
