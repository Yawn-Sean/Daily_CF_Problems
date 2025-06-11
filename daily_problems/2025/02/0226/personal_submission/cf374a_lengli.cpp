/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr i64 inf=2e18;

void solve(){
    i64 n,m,x1,y1,a,b;
    std::cin>>n>>m>>x1>>y1>>a>>b;
    std::vector<std::array<i64,2>> q(4);

    q[0]={x1-1,y1-1};
    q[1]={x1-1,m-y1};
    q[2]={n-x1,y1-1};
    q[3]={n-x1,m-y1};
    i64 res=inf;
    for(int i=0;i<4;i++){
        auto [l,r]=q[i];
        if(l%a==0 and r%b==0){
            i64 vl=l/a,vr=r/b;
            if(vl%2==vr%2){
                res=std::min(res,std::max(l/a,r/b));
            }
        }
    }

    if(res==inf) std::cout<<"Poor Inna and pony!"<<"\n";
    else std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
