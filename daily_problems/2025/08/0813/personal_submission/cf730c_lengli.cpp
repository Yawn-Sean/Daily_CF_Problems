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
    int n,m;
    std::cin>>n>>m;
    std::vector<std::vector<int>> eg(n+2);
    std::vector<std::vector<int>> d(n+2,std::vector<int> (n+2,-1));
    for(int i=1;i<=m;i++){
        int u,v;
        std::cin>>u>>v;
        eg[u].pb(v);
        eg[v].pb(u);
    }
    for(int i=1;i<=n;i++){
        std::queue<std::array<int,2>> q;
        q.push({0,i});
        while(q.size()){
            auto [w,u]=q.front();
            q.pop();
            if(d[i][u]!=-1) continue;
            d[i][u]=w;
            for(auto x:eg[u]){
                if(d[i][x]!=-1) continue;
                q.push({w+1,x});
            }
        }
    }
    
    int s;
    std::cin>>s;
    std::vector<std::array<int,3>> shop(s);
    for(auto &[c,k,p]:shop){
        std::cin>>c>>k>>p;
    }
    sort(all(shop),[&](auto l,auto r){
        return l[2]<r[2];
    });

    int q;
    std::cin>>q;
    while(q--){
        int to,cnt,lim;
        std::cin>>to>>cnt>>lim;

        auto check=[&](auto x)->bool{
            int ans=0,tmp=lim;
            for(auto [c,k,p]:shop){
                if(d[c][to]!=-1 and d[c][to]<=x){
                    if(tmp<p) break;
                    int o=std::min(tmp/p,k);
                    ans+=o;
                    tmp-=o*p;
                }
                if(ans>=cnt) return 1;
            }
            return 0;
        };

        int l=0,r=5000;
        while(l<r){
            int mid=(l+r)/2;
            if(check(mid)) r=mid;
            else l=mid+1;
        }
        if(!check(r)) r=-1;
        std::cout<<r<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
