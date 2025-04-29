/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

std::mt19937 rd(std::chrono::system_clock::now().time_since_epoch().count());

void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<std::vector<int>> g(n,std::vector<int> (m));
    for(auto &x:g)
        for(auto &y:x) std::cin>>y;
    

    int dis=0,eps=4;
    for(int i=0;i<m;i++){
        int len=std::abs(g[n/2-1][i]-g[n/2][i]);
        if(len<=eps) continue;
        else dis++;
    }

    int dis1=0;
    for(int i=0;i<m;i++){
        int len=std::abs(g[n-1][i]-g[0][i]);
        if(len<=eps) dis1++;
    }

    if(dis>m/2 and dis1>m/2) std::cout<<"YES"<<"\n";
    else std::cout<<"NO"<<"\n";
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
