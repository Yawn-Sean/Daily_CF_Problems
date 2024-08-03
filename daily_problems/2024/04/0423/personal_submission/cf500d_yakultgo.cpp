#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
vector<pair<int, int>> g[N];
int edge[N], sz[N];
ll cnt[N];
int n;
__int128_t sum = 0;
void dfs(int u, int fa) {
    sz[u] = 1;
    for (auto [v, i] : g[u]) {
        if (v == fa) continue;
        dfs(v, u);
        cnt[i] += 1ll * (sz[v]) * (sz[v] - 1) * (n - sz[v]) / 2;
        cnt[i] += 1ll * (n - sz[v]) * (n - sz[v] - 1) * sz[v] / 2;
        sz[u] += sz[v];
        sum += 2ll * edge[i] * cnt[i];
    }
};
void solve() {
    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, i});
        g[v].push_back({u, i});
        edge[i] = w;
    }
    dfs(1, 0);
    int q;
    cin >> q;
    ll b = 1ll * n * (n - 1) * (n - 2);
    while (q--) {
        int r, w;
        cin >> r >> w;
        sum -= 2ll * (edge[r] - w) * cnt[r];
        edge[r] = w;
        long double tmp = 6.0 * sum / b;
        cout << fixed << setprecision(16) << tmp << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}