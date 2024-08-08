#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
 
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> tree(n);
    vector<int> color(n, -1), group(n, -1), cnt(n);
    vector<ll> cntColor[2];
    cntColor[0].resize(n), cntColor[1].resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        tree[u].emplace_back(v);
        tree[v].emplace_back(u);
    }
    bool hasOddCycle = false;
    auto dfs = [&](auto&& dfs, int u, int col, int gid) -> void {
        color[u] = col;
        group[u] = gid;
        cnt[gid]++;
        cntColor[col][gid]++;
        for (int v : tree[u]) {
            if (color[v] == color[u]) hasOddCycle = true;
            else if (color[v] == -1) {
                dfs(dfs, v, col ^ 1, gid);
            }
        }
    };
    int maxSize = 0;
    for (int u = 0; u < n; u++) {
        if (group[u] == -1) {
            dfs(dfs, u, 0, u);
            maxSize = max(maxSize, cnt[u]);
        }
    }
    if (hasOddCycle) {
        cout << "0 1\n";
        return;
    }
    if (maxSize >= 3) {
        ll ans = 0;
        for (int u = 0; u < n; u++) {
            if (cnt[u] >= 3) {
                ans += cntColor[0][u] * (cntColor[0][u] - 1LL) / 2LL;
                ans += cntColor[1][u] * (cntColor[1][u] - 1LL) / 2LL;
            }
        }
        cout << 1 << " " << ans << "\n";
        return;
    }
    ll two = 0, one = 0;
    for (int u = 0; u < n; u++) {
        if (cnt[u] == 1) one++;
        if (cnt[u] == 2) two++;
    }
    ll need = 0, ans = 0;
    if (two == 0) {
        need = 3;
        ans = 1;
        for (int i = 0; i < 3; i++) {
            ans *= (one - i);
        }
        ans /= 6LL;
    } else {
        need = 2;
        for (int i = 0; i < two; i++) {
            ans += (n - 2);
        }
    }
    cout << need << " " << ans << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}
