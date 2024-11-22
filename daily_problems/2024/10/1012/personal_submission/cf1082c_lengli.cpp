/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

constexpr long long inf=1e18;

void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<std::vector<int>> eg(m+2);
    for(int i=1;i<=n;i++){
        int type,c;
        std::cin>>type>>c;
        eg[type].pb(c);
    }
    std::vector<long long> f(n+2,0);
    for(int i=1;i<=m;i++){
        sort(all(eg[i]),std::greater<>());
        long long sum=0;
        for(int j=1;j<=eg[i].size();j++){
            auto v=eg[i][j-1];
            sum+=v;
            if(sum<0) break;
            f[j]+=sum;
        }
    }
    std::cout<<*std::max_element(all(f))<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
