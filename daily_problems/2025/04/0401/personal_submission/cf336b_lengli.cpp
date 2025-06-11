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
    int m,R;
    std::cin>>m>>R;
    double res=0;
    double sq2=std::sqrt(2);

    auto cal=[&](int x){
        double res=(double)x*(2.0*sq2+2.0+x-1);
        return res;
    };

    for(int i=1;i<=m;i++){
        res+=2.0;
        if(i>1) res+=2+sq2+cal(i-2);
        if(i<m) res+=2+sq2+cal(m-i-1);
    }
    res*=R;
    res/=m;
    res/=m;
    std::cout<<std::fixed<<std::setprecision(10)<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
