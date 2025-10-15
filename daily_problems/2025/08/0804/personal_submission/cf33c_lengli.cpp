/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int inf=2e9;

void solve(){
    int n;
    std::cin>>n;
    std::vector<int> a(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];

    auto get=[&](std::vector<int> &q){
        std::vector<std::vector<int>> res(2,std::vector<int> (n+2,-2e9));
        res[0][1]=q[1],res[1][1]=-q[1];
        for(int i=2;i<=n;i++){
            res[0][i]=std::max(res[0][i],a[i]+std::max(res[1][i-1],res[0][i-1]));
            res[1][i]=std::max(res[1][i],-a[i]+res[1][i-1]);
        }
        return res;
    };

    auto pre=get(a);
    std::reverse(all(a));
    auto suf=get(a);
    std::reverse(all(suf[0]));
    std::reverse(all(suf[1]));

    int res=std::max(pre[0][n],pre[1][n]);
    res=std::max(res,suf[1][1]);
    res=std::max(res,suf[0][1]);

    for(int i=1;i<n;i++){
        res=std::max(res,pre[1][i]+suf[0][i+1]);
        res=std::max(res,pre[1][i]+suf[1][i+1]);
        res=std::max(res,pre[0][i]+suf[0][i+1]);
        res=std::max(res,pre[0][i]+suf[1][i+1]);
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
