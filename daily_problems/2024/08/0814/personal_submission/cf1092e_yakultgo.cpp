#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
struct dsu {
    vector<int> pa, size;
    explicit dsu(int size_) : pa(size_), size(size_, 1) {
        iota(pa.begin(), pa.end(), 0);
    }
    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (size[x] < size[y]) swap(x, y);
        pa[y] = x;
        size[x] += size[y];
    }
    int find(int x) {
        return pa[x] == x ? x : pa[x] = find(pa[x]);
    }
};
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> g[n + 1];
    vector<int> step(n + 1, 0), deg(n + 1, 0), flag(n + 1, 0);
    vector<int> mid(n + 1, 0);
    dsu ds(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++;
        deg[v]++;
        ds.unite(u, v);
    }
    map<int, vector<int>> group;
    for (int i = 1; i <= n; i++) {
        group[ds.find(i)].push_back(i);
    }
    for (auto &[k, v] : group) {
        queue<int> qu;
        for (auto &i : v) {
            if (deg[i] == 1) {
                qu.push(i);
            }
        }
        while (!qu.empty()) {
            int len = qu.size();
            int tmp;
            for (int i = 0; i < len; i++) {
                int u = qu.front();
                tmp = u;
                qu.pop();
                for (auto &v : g[u]) {
                    if (deg[v] > 0) {
                        deg[v]--;
                        if (deg[v] == 1) {
                            qu.push(v);
                        }
                    }
                }
            }
            if (!qu.empty()) {
                step[k]++;
            }
            if (qu.empty() && len >= 2) {
                step[k]++;
                flag[k] = 1;
            }
            mid[k] = tmp;
        }
    }
    for (int i = 1; i <= n; i++) {
        int fa = ds.find(i);
        if (mid[fa] == 0)
            mid[fa] = i;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int fa = ds.find(i);
        ans = max(ans, 2 * step[fa] - flag[fa]);
    }
    if (m == n - 1) {
        cout << ans << endl;
        return;
    }
    int f1 = 0, id1 = 0;
    for (int i = 1; i <= n; i++) {
        int fa = ds.find(i);
        if (mid[fa] == id1) continue;
        if (step[fa] >= f1) {
            f1 = step[fa];
            id1 = mid[fa];
        }
    }
    vector<pair<int, int>> res;
    for (auto &[k, v] : group) {
        if (mid[k] == id1) continue;
        res.push_back({mid[k], id1});
        g[mid[k]].push_back(id1);
        g[id1].push_back(mid[k]);
    }
    // 求直径
    vector<int> dep(n + 1, 0);
    function<void(int, int)> dfs = [&](int x, int fa) {
        for (auto &v : g[x]) {
            if (v == fa) continue;
            dep[v] = dep[x] + 1;
            dfs(v, x);
        }
    };
    dfs(id1, 0);
    int id = 0;
    for (int i = 1; i <= n; i++) {
        if (dep[i] >= dep[id]) {
            id = i;
        }
    }
    dep.assign(n + 1, 0);
    dfs(id, 0);
    int ans2 = 0;
    for (int i = 1; i <= n; i++) {
        ans2 = max(ans2, dep[i]);
    }
    cout << max(ans, ans2) << endl;
    for (auto &[u, v] : res) {
        cout << u << " " << v << endl;
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