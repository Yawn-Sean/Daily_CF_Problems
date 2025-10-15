/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

double C(int n,int m){
    i64 fz=1,fm=1;
    for(int i=0;i<m;i++) fz*=n-i;
    for(int i=1;i<=m;i++) fm*=i;
    return fz/fm;
}

void solve(){
    int n;
    double p;
    std::cin>>n>>p;
    double cnt=C(n,3);

    auto check=[&](int m){
        double t=C(m,3)+C(m,2)*C(n-m,1)+C(m,1)*C(n-m,2)*0.5;
        return t/cnt;
    };

    for(int i=0;i<=n;i++){
        if(check(i)>=p){
            std::cout<<i<<"\n";
            return;
        }
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
