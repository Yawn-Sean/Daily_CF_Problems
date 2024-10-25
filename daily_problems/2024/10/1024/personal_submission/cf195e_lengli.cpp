/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

constexpr int N=100010;

int p[N];
Mint d[N];
 
int find(int x){
    if(p[x]!=x){
        int t=p[x];
        p[x]=find(p[x]);
        d[x]+=d[t]; 
    }
    return p[x];
}

void solve(){
    int n;
    std::cin>>n;
    Mint res=0;
    for(int i=1;i<=n;i++){
        p[i]=i;
        int k;
        std::cin>>k;
        for(int j=0;j<k;j++){
            int v,x;
            std::cin>>v>>x;
            int u=find(v);
            Mint len=d[v]+x;
            p[u]=i;
            d[u]=len;
            res+=len;
        }
    }
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
