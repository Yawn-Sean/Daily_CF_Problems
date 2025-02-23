/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int N=1000010;
constexpr i64 inf=1e12;

int n,m,k;
i64 pre[N],suf[N];
std::array<int,4> airinfo[N];
i64 cost[N];

void calpre(){
    for(int i=1;i<=n;i++) cost[i]=inf;
    std::vector<std::array<int,4>> q;
    for(int i=1;i<=m;i++){
        if(!airinfo[i][2]) q.pb(airinfo[i]);
    }
    sort(all(q));
    pre[0]=1ll*n*inf;
    for(int i=1,j=0;i<N;i++){
        pre[i]=pre[i-1];
        while(j<q.size() and q[j][0]==i){
            auto id=q[j][1],v=q[j][3];
            if(cost[id]>v){
                pre[i]-=cost[id];
                cost[id]=v;
                pre[i]+=cost[id];
            }
            j++;
        }
    }
}

void calsuf(){
    for(int i=1;i<=n;i++) cost[i]=inf;
    std::vector<std::array<int,4>> q;
    for(int i=1;i<=m;i++){
        if(!airinfo[i][1]) q.pb(airinfo[i]);
    }
    sort(all(q),std::greater<>());
    suf[N-1]=1ll*n*inf;
    for(int i=N-2,j=0;i>=1;i--){
        suf[i]=suf[i+1];
        while(j<q.size() and q[j][0]==i){
            auto id=q[j][2],v=q[j][3];
            if(cost[id]>v){
                suf[i]-=cost[id];
                cost[id]=v;
                suf[i]+=cost[id];
            }
            j++;
        }
    }
}

void solve(){
    std::cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        auto &[d,f,t,c]=airinfo[i];
        std::cin>>d>>f>>t>>c;
    }
    calpre();
    calsuf();

    i64 res=inf;
    for(int i=2;i<N;i++){
        if(i+k<N and pre[i-1]<inf and suf[i+k]<inf){
            res=std::min(res,pre[i-1]+suf[i+k]);
        }
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
