#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1000050, inf = 0x3f3f3f3f, P = 998244353;
struct Edge {
    ll e, dis;
};
vector <Edge> g[N], gb[N];
vector <ll> f(N), w(N);
vector <int> dfn(N), low(N), stk(N), block(N);
bool instk[N];
int scc, snap, top;

void tarjan(int x){
    dfn[x] = low[x] = ++ snap;
    stk[++ top] = x, instk[x] = true;
    for (auto &it : g[x]){
        int y = it.e;
        if (!dfn[y]) tarjan(y), low[x] = min(low[x], low[y]);
        else if (instk[y]) low[x] = min(low[x], dfn[y]);
    }
    if (low[x] == dfn[x]){
        ++ scc;
        while (stk[top+1] != x){
            int y = stk[top--];
            instk[y] = false, block[y] = scc;
        }
    }
}
ll dfs(int x){
    if (f[x] >= 0) return f[x];
    f[x] = 0;
    for (auto &it : gb[x]){
        int y = it.e, dis = it.dis;
        f[x] = max(f[x], dfs(y) + dis);
    }
    f[x] += w[x];  //带点权dp
    return f[x];
}

void solve(){
    auto find = [&](ll x)->int{
        return (-1+sqrt(1+8*x))/2; //推公式或者二分
        // ll l = 0, r = 2e9;
        // while (l < r){
        //     ll mid = l+r+1 >> 1;
        //     if (mid*(mid+1) <= 2*x) l = mid;
        //     else r = mid-1;
        // }
        // return l;
    };
    auto func = [&](ll x)->ll{
        ll d = find(x);
        return x*(d+1) - d*(d+1)*(d+2)/6;
    };
    int n, m;
    cin >> n >> m;
    while (m--){
        ll a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }
    int S;
    cin >> S;
    tarjan(S);

    for (int u = 1; u <= n; ++ u)  //缩点建新图
        for (auto &it: g[u]){
            int v = it.e, dis = it.dis;
            int a = block[u], b = block[v];
            if (a == b){
                w[a] += func(dis);  //边权转点权
            } else {
                gb[a].push_back({b, dis});
            }
        }
    fill(f.begin(), f.end(), -1);
    ll res = 0;
    for (int i = 1; i <= scc; ++ i) 
        res = max(res, dfs(i));
    cout << res << "\n";
}
