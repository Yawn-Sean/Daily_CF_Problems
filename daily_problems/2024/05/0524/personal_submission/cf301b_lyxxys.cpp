#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7, INF = 1e9, N = 105, M = N;
struct Edge {
    ll ed, len;
};
vector <Edge> g[N];
vector <ll> w(N), dt(N);
ll ans, n, d;
bitset <N> vis;

bool dfs(int u, ll dis, ll val){
    if (u == n) return true;
    dt[u] = min(dt[u], dis-w[u]);  //用点权和边权更新最短距离
    if (dt[u] < 0) dt[u] = 0;
    dis = dt[u];
    for (auto &it : g[u]){
        ll ed = it.ed, len = it.len;
        if (val < dis+len) continue;
        if (dt[ed]+w[ed] > dis+len)  //贪心时加回点权
           if (dfs(ed, dis+len, val)) return true;
    }
    return false;
}

void solve(){
    cin >> n >> d;
    for (int i = 1; i <= n-2; ++ i) cin >> w[i+1];
    vector <array<int,2>> cor(n+1);
    for (int i = 1; i <= n; ++ i) cin >> cor[i][0] >> cor[i][1];

    auto distance = [&](int i, int j)->ll{
        return abs(cor[i][0]-cor[j][0]) + abs(cor[i][1]-cor[j][1]);
    };
    for (int i = 1; i <= n; ++ i)
        for (int j = i+1; j <= n; ++ j){
            ll delta = distance(i, j);
            g[i].push_back({j, delta*d});
            g[j].push_back({i, delta*d});
        }
    
    ll l = 0, r = 4e10;

    while (l < r){
        ll mid = l+r >> 1;
        fill(dt.begin(), dt.end(), 2e18), dt[1] = 0;
        if (dfs(1, 0, mid)) r = mid;
        else l = mid+1;
    }
    
    cout << l << "\n";
}
