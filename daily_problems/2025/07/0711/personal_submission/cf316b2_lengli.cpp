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
    int n,pos;
    std::cin>>n>>pos;
    std::vector<int> a(n+2);
    std::vector<std::vector<int>> eg(n+2);
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
        eg[a[i]].pb(i);
    }
    std::vector<int> sz,st(n+2);

    bool flag=0;
    int res=0;

    auto dfs=[&](auto self,int u,int len)->int{
        int cnt=1;
        if(u==pos){
            flag=1;
            res=len;
        }
        for(auto x:eg[u]){
            cnt+=self(self,x,len+1);
        }
        return cnt;
    };

    for(int i=1;i<=n;i++){
        if(!a[i]){
            flag=0;
            int v=dfs(dfs,i,1);
            if(!flag) sz.pb(v);
        }
    }

    std::vector<int> k(n+2);
    k[0]=1;
    for(auto x:sz){
        for(int j=n;j>=x;j--){
            k[j]|=k[j-x];
        }
    }
    for(int i=0;i<=n;i++){
        if(k[i]){
            std::cout<<i+res<<"\n";
        }
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
