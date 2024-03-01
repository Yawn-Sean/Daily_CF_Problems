//首先图不一定联通。
//对于一个联通块，能否染色，需要搜索所有的情况，整个过程中没有出现冲突即可。

/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) "lengli"
#endif

const int N=100010;

vector<int> eg[N];

void solve(){
    int n,m;
    cin>>n>>m;
    bool flag=1;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        eg[a].pb(b);
        eg[b].pb(a);
    }

    vector<vector<int>> res(2);
    vector<int> st(n+2,-1);
    function<void(int,int,int)> dfs=[&](int u,int f,int t){
        if(!flag) return;
        if(st[u]!=-1){
            if(st[u]!=t) flag=0;
            return;
        }
        st[u]=t;
        res[t].pb(u);
        for(auto x:eg[u]){
            if(x==f) continue;
            dfs(x,u,t^1);
        }
    };
    for(int i=1;i<=n;i++){
        if(st[i]==-1) dfs(i,0,0);
    }
    if(!flag){
        cout<<-1<<endl;
        return;
    }
    cout<<res[0].size()<<endl;
    for(auto x:res[0]) cout<<x<<" ";
    cout<<endl;
    cout<<res[1].size()<<endl;
    for(auto x:res[1]) cout<<x<<" ";
    cout<<endl;

}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
