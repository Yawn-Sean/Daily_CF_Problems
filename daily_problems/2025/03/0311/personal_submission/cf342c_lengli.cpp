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
    int r,h;
    std::cin>>r>>h;
    if(2*h>=r){
        int a=2+2*((h-((r+1)/2))/r);
        int b=1+2*(h/r);
        int c=3+2*((r+h)-(sqrt(3)/2+1)*r)/r;
        a=std::max(a,std::max(b,c));
        std::cout<<a<<"\n";
    }else std::cout<<1<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
