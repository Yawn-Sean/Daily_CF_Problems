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
    i64 x,y,m;
    std::cin>>x>>y>>m;
    if(x>=m or y>=m){
        std::cout<<0<<'\n';
        return;
    }
    if(x<=0 and y<=0){
        std::cout<<"-1"<<"\n";
        return;
    }

    i64 res=0;

    while(x<m and y<m){
        if(x>y) std::swap(x,y);

        i64 k=(y-x)/y;
        if(k==0) k=1;

        res+=k;
        x+=k*y;
    }
    
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
