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
    i64 n,m,x_1,y_1,x_2,y_2;
    std::cin>>n>>m>>x_1>>y_1>>x_2>>y_2;
    if(x_1>x_2) std::swap(x_1,x_2);
    if(y_1>y_2) std::swap(y_1,y_2);

    i64 a=x_1+n-x_2;
    i64 b=y_1+m-y_2;
    i64 res=n*m-a*b*2;
    if(a*2>n and b*2>m) res+=(a*2-n)*(b*2-m);
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
