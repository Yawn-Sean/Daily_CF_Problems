/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define all(x) x.begin(),x.end()
#define pb push_back
#define int long long

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) "lengli"
#endif

const int N=200010;

void solve(){
    int n;
    cin>>n;
    vector<int> a(N,0);
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        a[x]++;
    }
    vector<int> f(N,0),g(N,0);
    vector<vector<int>> eg(N);
    for(int i=1;i<=N/2;i++){
        if(i*2<N) eg[i].pb(i*2);
        if(i*2+1<N) eg[i].pb(i*2+1);
    }
    function<void(int,int)> dfs=[&](int u,int fa){
        for(auto x:eg[u]){
            if(x==fa) continue;
            dfs(x,u);
            f[u]+=f[x]+g[x];
            g[u]+=g[x];
        }
        g[u]+=a[u];
    };

    dfs(1,0);

    int res=f[1];

    for(int i=1;i<N;i++){
        if(g[i]==n){
            res=min(res,f[i]);
        }
    }
    function<void(int,int)> dfs1=[&](int u,int fa){
        res=min(res,f[u]);
        for(auto x:eg[u]){
            if(x==fa) continue;
            if(x!=u*2 and g[x]!=n) continue;
            int fx=f[x],fu=f[u];
            int gx=g[x],gu=g[u];

            g[u]-=g[x];
            f[u]-=f[x]+g[x];
            g[x]+=g[u];
            f[x]+=f[u]+g[u];
            dfs1(x,u);
            f[x]=fx,f[u]=fu;
            g[x]=gx,g[u]=gu;
        }
    };

    dfs1(1,0);

    cout<<res<<endl;
}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
