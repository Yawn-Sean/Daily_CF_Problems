#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7,N=2e5+10;
void solve(){
    int n;cin>>n;
    vector<vector<pair<int,int>>>g(n+1);
    for(int i=0,a,b,c;i<n-1;i++){
        cin>>a>>b>>c;
        g[a].push_back({b,c});
        g[b].push_back({a,-c});
    }
    int R=0,dn=0;
    int k;cin>>k;
    vector<int>q(k);
    vector<int>dfn(n+1),pw2(k+1);
    vector<vector<int>>mi(20,vector<int>(n+1));
    auto get=[&](int x,int y)->int{
        return dfn[x]<dfn[y]?x:y;
    };
    auto dfs=[&](auto&&dfs,int id,int f)->void{
        mi[0][dfn[id]=++dn]=f;
        for(auto[it,_]:g[id])if(it!=f)dfs(dfs,it,id);
    };
    auto lca=[&](int u,int v)->int{
        if(u==v)return u;
        if((u=dfn[u])>(v=dfn[v]))swap(u,v);
        int d=__lg(v-u++);
        return get(mi[d][u],mi[d][v-(1<<d)+1]);
    };
    auto init=[&]()->void{
        dfs(dfs,1,0);
        pw2[0]=1;
        for(int i=1;i<=k;i++)pw2[i]=pw2[i-1]*2%mod;
        for(int i=1;i<=__lg(n);i++)for(int j=1;j+(1<<i)-1<=n;j++){
            mi[i][j]=get(mi[i-1][j],mi[i-1][j+(1<<(i-1))]);
        }
    };
    init();
    int now=1,res=0;
    vector<int>up(n+1),down(n+1);
    for(auto&i:q){
        cin>>i;
        int x=lca(now,i);
        up[now]++;up[x]--;
        down[i]++;down[x]--;
        now=i;
    }
    auto dfs2=[&](auto&&dfs2,int u,int f)->void{
        for(auto&[x,y]:g[u]){
            if(x==f)continue;
            dfs2(dfs2,x,u);
            if(y){
                if(y==1){
                    res+=(pw2[up[x]]-1+mod)%mod;
                }else{
                    res+=(pw2[down[x]]-1+mod)%mod;
                }
                res=(res%mod+mod)%mod;
            }
            up[u]+=up[x];
            down[u]+=down[x];
        }
    };
    dfs2(dfs2,1,0);
    cout<<res;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
}