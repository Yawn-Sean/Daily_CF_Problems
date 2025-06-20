#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector adj(n + 1, vector<pair<int, bool>>());
    for(int i = 1; i < n; ++i) {
        int u, v;
        bool w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, 0);
        adj[v].emplace_back(u, w);
    }

    vector<bool> tag(n + 1), rtag(n + 1);
    vector fa(n + 1, vector<int> (20));
    vector<int> dep(n + 1);

    auto dfs = [&](this auto&& self, int cur) -> void {
        dep[cur] = dep[fa[cur][0]] + 1;
        for(int i = 1; fa[cur][i - 1]; ++i) {
            fa[cur][i] = fa[fa[cur][i - 1]][i - 1];
        }
        for(auto [to, w] : adj[cur]) {
            if(to == fa[cur][0]) {
                if(w) tag[cur] = 1;
                continue;
            }
            if(w) rtag[to] = 1;
            fa[to][0] = cur;
            self(to);
        }
    };
    dfs(1);

    auto lca = [&](int u, int v) -> int {
        if(dep[u] < dep[v]) swap(u, v);
        if(dep[u] > dep[v]) {
            int dif = dep[u] - dep[v];
            for(int i = 19; ~i; --i) {
                if(dif >> i & 1) u = fa[u][i];
            }
        }
        if(u == v) return u;
        for(int i = 19; ~i; --i) {
            if(fa[u][i] == fa[v][i]) continue;
            u = fa[u][i];
            v = fa[v][i];
        }
        return fa[u][0];
    };

    int k;
    cin >> k;
    vector<ll> p(k + 1, 0);
    p[0] = 1;
    for(int i = 1; i <= k; ++i) p[i] = p[i - 1] * 2 % MOD;

    vector<int> dif(n + 1), rdif(n + 1);

    int cur = 1;
    for(int i = 1; i <= k; ++i) {
        int x;
        cin >> x;
        int p = lca(cur, x);
        dif[cur]++;
        dif[p]--;
        rdif[x]++;
        rdif[p]--;
        cur = x;
    }

    ll ans = 0;

    auto dfs2 = [&](this auto&& self, int cur) -> void {
        for(auto [to, w] : adj[cur]) {
            if(to == fa[cur][0]) continue;
            self(to);
            dif[cur] += dif[to];
            rdif[cur] += rdif[to];
        }
        if(tag[cur]) {
            ans += p[dif[cur]] - 1;
            ans %= MOD;
        }
        if(rtag[cur]) {
            ans += p[rdif[cur]] - 1;
            ans %= MOD;
        }
    };
    dfs2(1);

    cout << ans << "\n";
}
