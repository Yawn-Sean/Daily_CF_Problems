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
    std::vector<std::array<int,3>> pt(n);
    for(auto &[x,y,z]:pt) std::cin>>x>>y>>z;

    auto dis=[&](auto l,auto r)->double{
        double dx=pt[l][0]-pt[r][0];
        double dy=pt[l][1]-pt[r][1];
        double dz=pt[l][2]-pt[r][2];
        double sum=dx*dx+dy*dy+dz*dz;
        return std::sqrt(sum);
    };

    double res=1000000000;

    for(int i=1;i<n;i++){
        for(int j=1;j<i;j++){
            res=std::min(res,dis(0,i)+dis(0,j)+dis(i,j));
        }
    } 

    res/=2.0;

    std::cout<<std::fixed<<std::setprecision(10)<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
