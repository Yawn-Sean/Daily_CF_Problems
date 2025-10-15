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
    int a,b,x_1,y_1,x_2,y_2;
    std::cin>>a>>b>>x_1>>y_1>>x_2>>y_2;
    a*=2,b*=2;
    int b1=y_1-x_1;
    int b2=y_2-x_2;
    int a1=y_1+x_1;
    int a2=y_2+x_2;

    x_1=b1/b+(b1>0);
    x_2=b2/b+(b2>0);
    y_1=a1/a+(a1>0);
    y_2=a2/a+(a2>0);
    std::cout<<std::max(std::abs(x_2-x_1),std::abs(y_2-y_1))<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
