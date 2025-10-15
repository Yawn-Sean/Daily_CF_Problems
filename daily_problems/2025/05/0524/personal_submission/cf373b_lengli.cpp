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
    i64 w,m,k;
    std::cin>>w>>m>>k;
    i64 x=1,y=0,z=m;
    w/=k;
    while(x<m) x*=10,y++;
    while(w>=x*y-z*y){
        w-=x*y-z*y;
        z=x;
        x*=10;
        y++;
    }
    std::cout<<z+w/y-m<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
