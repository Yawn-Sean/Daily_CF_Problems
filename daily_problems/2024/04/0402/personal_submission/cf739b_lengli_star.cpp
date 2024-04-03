//我们考虑每个点的贡献
//可以发现是一条向上(根节点)的简单路径
//那么我没可以倍增的找到第一个路径长度大于当前节点权值的节点
//然后使用树上差分维护贡献
//最后dfs一下统计子树总和即可。
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

const int N=100010;

struct LCA{
    vector<int> dep,dist;
    vector<vector<array<int,2>>> eg;
    vector<vector<int>> fa;
    int m;
    void init(int n){
        m=log(n)/log(2)+1;
        eg.clear(),dep.clear(),fa.clear();
        eg.resize(n+1),dep.resize(n+1,0),dist.resize(n+1,0);
        fa.resize(n+1,vector<int> (m+1,0));
    }
    
    void dfs(int u, int f) {
        for (int i = 1; i <= m; i++) {
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
        }
        for (auto [j,w]:eg[u]) {
            if (j == f) continue;
            fa[j][0] = u;
            dep[j] = dep[u] + 1;
            dist[j] = dist[u] + w;
            dfs(j, u);
        }
    }
    
    int get(int a, int x) {
        int u=a;
        for (int i = m; i >= 0; i--) {
            if (dep[u] - (1 << i) >= 0){
                int v=fa[u][i];
                if(dist[a]-dist[v]>x) continue;
                u=v;
            }
        }
        return u;
    }
}tr;

void solve(){
    int n;
    cin>>n;
    tr.init(n);
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=2;i<=n;i++){
        int p,w;
        cin>>p>>w;
        tr.eg[p].pb({i,w});
    }
    tr.dfs(1,0);

    vector<int> b(n+1);

    for(int i=1;i<=n;i++){
        int u=tr.get(i,a[i]);
        b[tr.fa[i][0]]++;
        b[tr.fa[u][0]]--;
    }
    vector<int> res(n+1);
    int cnt=0;
    function<int(int,int)> dfs=[&](int u,int f){
        int ans=0;
        for(auto [x,w]:tr.eg[u]){
            if(x==f) continue;
            ans+=dfs(x,u);
        }
        ans+=b[u];
        res[u]=ans;
        return ans;
    };

    dfs(1,0);
    for(int i=1;i<=n;i++) cout<<res[i]<<" ";
}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
