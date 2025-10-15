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
    int n;
    std::cin>>n;
    std::vector<std::array<int,2>> a(n);
    for(auto &[l,v]:a) std::cin>>l>>v;
    std::sort(all(a),[&](auto x,auto y){
        return x[0]>y[0];
    });
    double res=0;
    int pos=0;
    for(int i=0;i<n;i++){
        if(a[i][1]<=a[pos][1]) pos=i;
        else{
            double ans=1.0*(a[pos][0]-a[i][0])/(a[i][1]-a[pos][1]);
            res=std::max(res,ans);
        }
    }
    std::cout<<std::fixed<<std::setprecision(10)<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
