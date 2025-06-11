/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n;
    std::cin>>n;
    std::vector<int> a(n+2),s(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];
    for(int i=1;i<=n;i++){
        char c;
        std::cin>>c;
        s[i]=(c=='1');
    }
    std::vector<int> f(n+2,-1);

    auto dfs=[&](auto self,int pos,int limit)->int{
        if(pos==0) return 0;
        if(!limit and f[pos]!=-1) return f[pos];
        int mx=limit ? s[pos] : 1;
        int res=0;
        for(int i=0;i<=mx;i++){
            auto ans=self(self,pos-1,limit and i==mx);
            if(i==1) res=std::max(res,ans+a[pos]);
            else res=std::max(res,ans);
        }
        if(!limit) f[pos]=res;
        return res;
    };

    std::cout<<dfs(dfs,n,1);
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
