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
    int n,m;
    std::cin>>n>>m;
    std::vector<std::array<int,2>> val(n+2);
    for(int i=1;i<=n;i++) {
        std::cin>>val[i][0]>>val[i][1];
    }
    std::vector<int> id(n+2);
    for(int i=1;i<=n;i++) id[i]=i;
    sort(id.begin()+1,id.begin()+1+n,[&](auto l,auto r){
        return val[l][0]+val[r][1]<val[l][1]+val[r][0];
    }); 
    std::vector<int> sum(n+2);
    std::vector<int> pre(n+2),suf(n+2);
    for(int i=1;i<=n;i++) pre[i]=val[id[i]][0]+pre[i-1];
    for(int i=n;i>=1;i--) suf[i]=val[id[i]][1]+suf[i+1];

    for(int i=1;i<=n;i++){
        int j=id[i];
        int v=(i-1)*val[j][1]+(n-i)*val[j][0];
        v+=pre[i-1]+suf[i+1];
        sum[j]=v;
    }
    while(m--){
        int u,v;
        std::cin>>u>>v;
        int k=std::min(val[u][0]+val[v][1],val[u][1]+val[v][0]);
        sum[u]-=k,sum[v]-=k;
    }
    for(int i=1;i<=n;i++) std::cout<<sum[i]<<" ";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
