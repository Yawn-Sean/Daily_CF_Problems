/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

void solve(){
    i64 n,k;
    std::cin>>n>>k;
    std::vector<i64> f(n+2);
    f[1]=1,f[2]=2;
    for(int i=3;i<=n;i++) f[i]=f[i-1]+f[i-2];
    std::vector<int> res(n);

    auto dfs=[&](auto self,int pos,int t){
        if(pos>=n) return;
        if(t<=1 or k<=f[t-1]){
            res[pos]=pos+1;
            self(self,pos+1,t-1);
        }else{
            res[pos+1]=pos+1;
            res[pos]=pos+2;
            k-=f[t-1];
            self(self,pos+2,t-2);
        }
    };  

    dfs(dfs,0,n);

    for(auto x:res) std::cout<<x<<" ";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
