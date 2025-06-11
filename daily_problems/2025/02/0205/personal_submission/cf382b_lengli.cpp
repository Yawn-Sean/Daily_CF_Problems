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
    i64 a,b,w,x,c;
    std::cin>>a>>b>>w>>x>>c;

    if(a>=c){
        std::cout<<0<<"\n";
        return;
    }

    i64 v=w*(c-a)-b+(w-x)-1;

    i64 res=v/(w-x);
    
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
