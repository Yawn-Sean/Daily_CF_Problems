/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

using i64=long long;

void solve(){
    int n;
    std::cin>>n;
    std::vector<std::array<int,3>> circle(n);
    for(auto &[r,x,y]:circle) std::cin>>x>>y>>r;
    sort(all(circle),std::greater<>());

    auto isin=[&](std::array<int,3> l,std::array<int,3> r){
        i64 len=l[0]+r[0];len*=len;
        i64 dx=l[1]-r[1],dy=l[2]-r[2];
        i64 k=dx*dx+dy*dy;
        return k<len;
    };

    i64 cnt=0;

    for(int i=0;i<n;i++){
        int t=0;
        for(int j=0;j<i;j++){
            if(isin(circle[i],circle[j])) t++;
        }
        auto [r,x,y]=circle[i];
        if(t<2) cnt+=1ll*r*r;
        else{
            t-=2;
            if(t&1) cnt+=1ll*r*r;
            else cnt-=1ll*r*r;
        }
    }

    double res=std::acos(-1)*cnt;
    std::cout<<std::fixed<<std::setprecision(10)<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
