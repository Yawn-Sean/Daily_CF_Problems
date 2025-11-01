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
    int n;
    std::cin>>n;
    std::vector<int> a(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];
    std::vector<std::vector<int>> eg(n+2);
    for(int i=2;i<=n;i++){
        int p;
        std::cin>>p;
        eg[p].pb(i);
        eg[i].pb(p);
    }

    int res=0;

    auto dfs=[&](auto self,int u,int fa,int dep)->std::array<int,2>{
        int mx1=-1,mx2=-1;
        int val=a[u]+dep;
        for(auto x:eg[u]){
            if(x==fa) continue;
            auto t=self(self,x,u,dep+1);
            if(mx1!=-1){
                res=std::max(res,mx1+t[0]-2*dep);
            }
            if(t[0]>mx1){
                mx2=mx1;
                mx1=t[0];
            }else if(t[0]>mx2){
                mx2=t[0];
            }
            if(t[1]>mx1){
                mx2=mx1;
                mx1=t[1];
            }else if(t[1]>mx2){
                mx2=t[1];
            }
        }
        if(mx1!=-1){
            res=std::max(res,mx1+val-2*dep);
        }
        if(val>mx1){
            mx2=mx1;
            mx1=val;
        }else if(val>mx2){
            mx2=val;
        }
        return {mx1,mx2};
    };
   
    dfs(dfs,1,0,0);

    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
