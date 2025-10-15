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
    int a,b,c,d,p;
    std::cin>>a>>b>>c>>d>>p;
    a-=c,b-=c,d-=c-1;
    p=0;
    if(d==2) a--,b--,p=3;
    if(d==1){
        if(a) a--,p=1;
        else b--,p=2;
    }
    if(a<0 or b<0 or d>2 or d<0){
        std::cout<<"-1"<<"\n";
        return;
    }
    if(p&2) std::cout<<7;
    for(int i=0;i<a;i++) std::cout<<4;
    for(int i=0;i<c;i++) std::cout<<47;
    for(int i=0;i<b;i++) std::cout<<7;
    if(p&1) std::cout<<4;
    std::cout<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
