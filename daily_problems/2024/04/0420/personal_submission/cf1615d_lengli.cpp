/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define all(x) x.begin(),x.end()
#define pb push_back

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) "lengli"
#endif

const int N=100010;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<array<int,2>>> eg(n+1),g(n+1);
    vector<array<int,3>> edge;
    for(int i=1;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        eg[a].pb({b,c});
        eg[b].pb({a,c});
        if(c!=-1){
            int t=__builtin_popcount(c)&1;
            g[a].pb({b,t});
            g[b].pb({a,t});
        }
        edge.pb({a,b,c});
    }

    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].pb({b,c});
        g[b].pb({a,c});
    }

    vector<int> st(n+1,0),val(n+1,-1);
    bool flag=1;
    function<void(int,int,int)> dfs=[&](int u,int fa,int w){
        if(st[u]){
            if(w!=val[u]) flag=0;
            return;
        }
        st[u]=1,val[u]=w;
        for(auto [x,c]:g[u]){
            if(x==fa) continue;
            dfs(x,u,w^c);
        }
    };

    for(int i=1;i<=n;i++){
        if(!st[i]) dfs(i,0,0);
    }

    if(!flag){
        cout<<"NO"<<endl;
        return;
    }

    cout<<"YES"<<endl;

    function<void(int,int)> dfs1=[&](int u,int fa){
        for(auto [x,c]:eg[u]){
            if(x==fa) continue;
            if(c==-1){
                cout<<u<<" "<<x<<" "<<(val[x]^val[u])<<endl;
            }else cout<<u<<" "<<x<<" "<<c<<endl;
            dfs1(x,u);
        }
    };
    
    dfs1(1,0);
}

signed main(){
    fastio;
    int T;
    cin>>T;
    while(T--) solve();
    
    return 0;
}
