/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

#define int long long

void solve(){
    int n,a,b;
    std::cin>>n>>a>>b;
    std::map<int,int> q;
    std::map<std::array<int,2>,int> p;
    long long res=0;
    for(int i=1;i<=n;i++){
        int x,vx,vy;
        std::cin>>x>>vx>>vy;
        int t=a*vx-vy;
        res+=q[t];
        res-=p[{vx,vy}];
        q[t]++;
        p[{vx,vy}]++;
    }
    std::cout<<res*2<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
