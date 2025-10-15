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
    int n,s,m;
    std::cin>>n>>s>>m;
    s--;
    std::vector<int> a(n);
    int mx=0;
    for(auto &x:a) std::cin>>x,mx+=x;
    std::vector<std::vector<int>> f(n,std::vector<int> (mx+1,-1));
    std::string col;
    std::cin>>col;


    for(int i=0;i<n;i++) f[i][a[i]]=std::abs(i-s);

    auto dfs=[&](auto self,int idx,int sum)->int{
        if(f[idx][sum]!=-1) return f[idx][sum];
        if(sum==0){
            f[idx][sum]=std::abs(idx-s);
            return f[idx][sum];
        }
        if(idx==s){
            if(sum==a[idx]) return f[idx][sum]=0;
        }
        int c=col[idx];
        int ans=inf;
        for(int i=0;i<n;i++){
            if(a[i]>=a[idx] or col[i]==c) continue;
            if(sum>=a[idx]) {
                auto t=self(self,i,sum-a[idx]);
                if(t==inf) continue;
                ans=std::min(t+std::abs(i-idx),ans);
            }
        }
        return f[idx][sum]=ans;
    };

    int res=inf;

    for(int i=0;i<n;i++){
        for(int j=m;j<=mx;j++)
            res=std::min(res,dfs(dfs,i,j));
    }
    if(res==inf) res=-1;
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
