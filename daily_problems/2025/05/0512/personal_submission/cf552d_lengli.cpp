/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

#define int long long

constexpr int inf=1e9;

void solve(){
    int n;
    std::cin>>n;
    std::vector<std::array<int,2>> a(n);
    for(auto &[x,y]:a) std::cin>>x>>y;
    std::map<std::array<i64,2>,int> q;

    auto cal=[&](i64 x)->i64{
        return x*(x-1)*(x-2)/6;
    };

    i64 res=cal(n);
    for(int i=0;i<n;i++){
        q.clear();
        for(int j=0;j<n;j++){
            if(i==j) continue;
            int dx=a[j][0]-a[i][0];
            int dy=a[j][1]-a[i][1];
            if(dx<0) dx*=-1,dy*=-1;
            int g=std::__gcd(dx,dy);
            if(!g){
                if(dx) dx=1;
                else dy=1;
            }else dx/=g,dy/=g;
            if(j<=i) q[{dx,dy}]=-inf;
            else q[{dx,dy}]++;
        }
        for(auto [x,v]:q){
            if(v<=0) continue;
            res-=cal(v+1);
        }
    }
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
