// #pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>

using namespace std;
using i64=long long;
using u32=unsigned;
using u64=unsigned long long;

using i128=__int128;
using u128=unsigned __int128;

// constexpr int inf=numeric_limits<int>::max()/2;
// constexpr i64 INF=numeric_limits<i64>::max()/2;

constexpr int mod=1e9+7;

i64 fastpow(i64 a,int b,int p) {
    i64 res=1%p;
    while(b){
        if(b&1){
            res=res*a%p;
        }
        a=a*a%p;
        b>>=1;
    }
    return res;
}



void solve(){
    int n;
    cin>>n;

    vector<vector<int>> G(n,vector<int>{});
    map<pair<int,int>,int> E;
    for(int i=0;i<n-1;i++){
        int u,v,x;
        cin>>u>>v>>x;
        u--,v--;
        G[u].push_back(v);
        G[v].push_back(u);
        if(x==0){
            E[{u,v}]=0;
            E[{v,u}]=0;
        }else{
            E[{u,v}]=1;
            E[{v,u}]=-1;
        }
    }


    vector<int> depth(n);
    const int log_n=17;
    vector<vector<int>> pa(n,vector<int>(log_n,-1));
    auto dfs=[&](auto dfs,int u,int fa,int d)->void{
        depth[u]=d;
        pa[u][0]=fa;
        for(int i=1;i<log_n;i++){
            int p=pa[u][i-1];
            if(p!=-1)
                pa[u][i]=pa[p][i-1];
        }
        for(auto v:G[u]){
            if(v==fa){
                continue;
            }
            dfs(dfs,v,u,d+1);
        }

    };
    dfs(dfs,0,-1,0);

    auto lca=[&](int u,int v)->int{
        if(depth[u]<depth[v])
            swap(u,v);
        for(int i=log_n-1;i>=0;i--){
            int p=pa[u][i];
            if(p!=-1&&depth[p]>=depth[v])
                u=p;
        }
        if(u==v)
            return u;
        for(int i=log_n-1;i>=0;i--){
            int pu=pa[u][i];
            int pv=pa[v][i];
            if(pu!=-1&&pv!=-1&&pu!=pv){
                u=pu;
                v=pv;
            }
        }
        return pa[u][0];
    };

    vector<int> s={0};
    int k;
    cin>>k;
    for(int i=0;i<k;i++){
        int si;
        cin>>si;
        si--;
        s.push_back(si);
    }

    vector<int> diff_up(n),diff_down(n);
    for(int i=0;i<k;i++){
        int u=s[i],v=s[i+1];
        int l=lca(u,v);
        diff_up[u]++,diff_up[l]--;
        diff_down[v]++,diff_down[l]--;
    }

    auto traverse=[&](auto traverse,int u,int fa)->void{
        for(auto v:G[u]){
            if(v==fa){
                continue;
            }
            traverse(traverse,v,u);
            diff_up[u]+=diff_up[v];
            diff_down[u]+=diff_down[v];
        }
        return;
    };
    traverse(traverse,0,-1);

    i64 ans=0;
    for(int i=0;i<n;i++){
        int p=pa[i][0];
        if(p!=-1){
            if(E[{i,p}]==1){
                ans+=(fastpow(2,diff_down[i],mod)-1+mod)%mod;
                ans%=mod;
            }else if(E[{i,p}]==-1){
                ans+=(fastpow(2,diff_up[i],mod)-1+mod)%mod;
                ans%=mod;
            }
        }
    }

    cout<<ans<<"\n";


}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test=1;
    // cin>>test;
    while(test--){
        solve();
    }
 
    
    
    return 0;
}
