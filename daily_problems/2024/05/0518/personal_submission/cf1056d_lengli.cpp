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

int n;
vector<int> eg[N];
int f[N];

int dfs(int u,int fa){
    int son=0;
    int sum=0;
    for(auto x:eg[u]){
        if(x==fa) continue;
        son++;
        sum+=dfs(x,u);
    }
    if(son==0) return f[u]=1;
    return f[u]=sum;
}

void solve(){
    cin>>n;
    for(int i=2;i<=n;i++){
        int u=i,v;
        cin>>v;
        eg[u].pb(v);
        eg[v].pb(u);
    }

    dfs(1,0);

    vector<int> q;
    for(int i=1;i<=n;i++) q.pb(f[i]);
    sort(all(q));
    for(auto x:q) cout<<x<<" ";
}

signed main(){

    #ifndef ONLINE_JUDGE
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif

    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
