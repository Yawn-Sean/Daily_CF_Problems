/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define int long long

void solve(){
    int n,k;
    std::cin>>n>>k;
    std::vector<std::vector<int>> q(k+2); 
    for(int i=1;i<=n;i++){
        int x;
        std::cin>>x;
        for(int j=1,sum=x;j<=k;j++,sum+=x) q[j].pb(sum);
    }

    int m;
    std::cin>>m;
    while(m--){
        int x;
        std::cin>>x;
        int res=1e18;
        for(int j=1;j<=k;j++){
            for(auto c:q[j]){
                if(x==c) res=std::min(res,j);
                int nd=x-c;
                if(nd<=0) continue;
                for(int l=1;l<=k-j;l++){
                    auto it=lower_bound(all(q[l]),nd)-q[l].begin();
                    if(it<0 or it>=(int)q[l].size()) continue;
                    int v=q[l][it];
                    if(v==nd) res=std::min(res,l+j);
                }
            }
        }
        if(res==1e18) res=-1;
        std::cout<<res<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
