/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int inf=1e9;

void solve(){
    int n;
    std::cin>>n;
    int res=inf;

    auto dfs=[&](auto self,int a,int b)->int{
        if(!b) return 1e9;
        if(b==1) return a-1;
        return self(self,b,a%b)+a/b;
    };

    for(int i=1;i<=n;i++) res=std::min(res,dfs(dfs,n,i));

    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
