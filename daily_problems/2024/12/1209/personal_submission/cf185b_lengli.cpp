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
    i64 s;
    std::cin>>s;
    i64 a,b,c;
    std::cin>>a>>b>>c;
    if(a==0 and b==0 and c==0){
        std::cout<<"0 0 0"<<"\n";
        return;
    }
    i64 sum=a+b+c;
    double x=(1.0*a*s)/(1.0*sum);
    double y=(1.0*b*s)/(1.0*sum);
    double z=(1.0*c*s)/(1.0*sum);
    std::cout<<std::fixed<<std::setprecision(10);
    std::cout<<x<<" "<<y<<" "<<z<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
