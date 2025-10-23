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
    int n,a,b;
    std::cin>>n>>a>>b;
    std::vector<int> v(n+2),t(n+2);
    for(int i=1;i<=n;i++) std::cin>>v[i]>>t[i];

    i64 res=0;

    std::map<i64,int> q;

    auto dfs=[&](auto self,int l,int r,int sv,int st,int cnt,int op)->void{
        if(cnt){
            if(1ll*a*st==1ll*b*sv) res++;
            if(op){
                res+=q[1ll*b*sv-1ll*a*st];
            }else{
                q[1ll*a*st-1ll*b*sv]++;
            }
        }
        for(int i=l;i<=r;i++){
            self(self,i+1,r,sv+v[i],st+t[i],cnt+1,op);
        }
    };

    dfs(dfs,1,n/2,0,0,0,0);
    dfs(dfs,n/2+1,n,0,0,0,1);

    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
