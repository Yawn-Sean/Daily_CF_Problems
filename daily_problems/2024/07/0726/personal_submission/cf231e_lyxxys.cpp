#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 1e5+10, mod = 1e9 + 7, inf = 1e9;
vector <int> g[N], gs[N], dfn(N), low(N), stk(N), bin(N);
vector <int> Val(N), dep(N, -1);
int f[N][20], snap, top, tot;
void tarjan(int x, int fa){
    dfn[x] = low[x] = ++ snap;
    stk[++ top] = x;
    for (auto &y : g[x]){
        if (!dfn[y]){
            tarjan(y, x);
            low[x] = min(low[x], low[y]);
        } else if (y != fa) low[x] = min(low[x], dfn[y]);
    }
    if (dfn[x]==low[x]){
        ++ tot;
        int cnt = 0;
        while (stk[top+1] != x){
            int y = stk[top--];
            bin[y] = tot;
            ++ cnt;
        }
        if (cnt > 1) Val[tot] = 1;
    }
}
void bfs(int rt){
    queue<int> Q;
    Q.push(rt);
    dep[rt] = 0;

    while (!Q.empty()){
        int u = Q.front();
        Q.pop();
        for (auto&x : gs[u]){
            if (dep[x]==-1){
                Q.push(x);
                dep[x] = dep[u] + 1;
                Val[x] += Val[u];
                f[x][0] = u;
                for (int k = 1; 1<<k <= dep[x]; ++ k){
                    f[x][k] = f[f[x][k-1]][k-1];
                }
            }
        }
    }
}
int lca(int x, int y){
    if (dep[x] < dep[y]) swap(x, y);
    for (int k = 0, d=dep[x]-dep[y]; 1<<k <= d; ++ k){
        if (d>>k & 1){
            x = f[x][k];
        }
    }
    if (x == y) return x;
    for (int k = log2(dep[x]); k >= 0; -- k){
        if (f[x][k] != f[y][k]){
            x = f[x][k];
            y = f[y][k];
        }
    }
    return f[x][0];
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<ll> mi2(n+1);
    mi2[0] = 1;
    for (int i = 1; i <= n; ++ i) mi2[i] = mi2[i-1]*2%mod;

    while (m--){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = 1; i <= n; ++ i){
        if (!dfn[i]){
            tarjan(i, 0);
        }
    }

    for (int u = 1; u <= n; ++ u){
        for (auto &x : g[u]){
            int a = bin[u], b = bin[x];
            if (a != b){
                gs[a].push_back(b);
                gs[b].push_back(a);
            }
        }
    }
    bfs(1);

    int q;
    cin >> q;

    while (q--){
        int a, b;
        cin >> a >> b;
        a = bin[a], b = bin[b];
        int anc = lca(a, b), fanc = f[anc][0];
        cout << mi2[Val[a]+Val[b]-Val[anc]-Val[fanc]] << "\n";
    }
}
