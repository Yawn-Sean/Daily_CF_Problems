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
    int x_1,y_1,x_2,y_2;
    std::cin>>x_1>>y_1>>x_2>>y_2;
    i64 res=(y_2-y_1)/2+1;
    res*=(x_2-x_1+1);
    res-=(x_2-x_1)/2;
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
