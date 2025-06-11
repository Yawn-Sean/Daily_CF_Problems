/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

const int N=200010,M=20;

struct MA{
    int f[N][M];
    void init(std::vector<int> a,int n){
        for(int len=0;len<M;len++){
            for(int i=1;i+(1<<len)-1<=n;i++){
                if(!len) f[i][len]=a[i];
                else f[i][len]=std::max(f[i][len-1],f[i+(1<<len-1)][len-1]);
            }
        }
    }
    int query(int l,int r){
        int k=log(r-l+1)/log(2);
        return std::max(f[l][k],f[r-(1<<k)+1][k]);
    }
}ma;
struct MI{
    int f[N][M];
    void init(std::vector<int> a,int n){
        for(int len=0;len<M;len++){
            for(int i=1;i+(1<<len)-1<=n;i++){
                if(!len) f[i][len]=a[i];
                else f[i][len]=std::min(f[i][len-1],f[i+(1<<len-1)][len-1]);
            }
        }
    }
    int query(int l,int r){
        int k=log(r-l+1)/log(2);
        return std::min(f[l][k],f[r-(1<<k)+1][k]);
    }
}mi;

std::vector<int> idx[N*10];

void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<int> a(n+2);
    for(int i=1;i<=n;i++) {
        std::cin>>a[i];
        idx[a[i]].pb(i);
    }
    ma.init(a,n),mi.init(a,n);

    auto find=[&](int v,int x){
        auto &q=idx[v];
        auto it=lower_bound(all(q),x)-q.begin();
        return q[it];
    };

    while(m--){
        int l,r,x;
        std::cin>>l>>r>>x;
        int mx=ma.query(l,r);
        int mn=mi.query(l,r);
        if(mx==mn and mx==x) std::cout<<"-1"<<"\n";
        else if(mx==x) std::cout<<find(mn,l)<<"\n";
        else std::cout<<find(mx,l)<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
