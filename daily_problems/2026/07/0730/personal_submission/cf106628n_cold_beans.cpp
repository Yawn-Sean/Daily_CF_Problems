#include <bits/stdc++.h>
using namespace std;
#define int long long

struct st_tree {
    vector<array<int, 30>> f, mn, mx;
    vector<vector<int>> edges;
    vector<int> dep, val, accu;
    int n;

    st_tree(int n) : n(n), f(n + 1), edges(n + 1), dep(n + 1, 0), val(n+1), mn(n+1), mx(n+1), accu(n+1) {}

    void add_edge(int u, int v, int b) {
        edges[v].push_back(u);
        val[u] = b;
    }

    void dfs(int x, int fa) {
        f[x][0] = fa; mn[x][0] = val[x]; mx[x][0] = val[x];
        dep[x] = dep[fa] + 1;
        for (auto to : edges[x]) {
            if (to == fa) continue;
            dfs(to, x);
        }
    }

    int lca(int u, int v) {
        if (dep[u] < dep[v]) swap(u, v);
        for (int i = 29; i >= 0; i--) {
            if (dep[f[u][i]] >= dep[v]) u = f[u][i];
        }
        if (u == v) return u;
        for (int i = 29; i >= 0; i--) {
            if (f[u][i] != f[v][i]) {
                u = f[u][i];
                v = f[v][i];
            }
        }
        return f[u][0];
    }

    void init() {
        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 1; i <= n; i++) {
                mn[i][j] = 1e10;
            }
        }
        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 1; i <= n; i++) {
                f[i][j] = f[f[i][j - 1]][j - 1];
                mn[i][j] = min(mn[i][j-1], mn[f[i][j-1]][j-1]);
                mx[i][j] = max(mx[i][j-1], mx[f[i][j-1]][j-1]);
            }
        }
    }

    auto make() {
        vector<int> ans(n+1);
        vector<int> order(n+1); iota(order.begin(), order.end(), 0);
        sort(order.begin() + 1, order.end(), [&](int i, int j) {
            return dep[i] > dep[j];
        });
        for (int i = 1; i <= n; i++) {
            int id = order[i];
            ans[id] = accu[id];
            for (auto to: edges[id]) ans[id] += ans[to];
        }
        return ans;
    }

    void build(int s) {
        dfs(s, 0);
        init();
    }
};

void run_case() {
    int n;
    cin >> n;
    vector<int> apples(n+1);
    for (int i = 1; i <= n; i++) cin >> apples[i];
    st_tree tree(n);
    for (int i = 1; i < n; i++) {
        int v, val;
        cin >> v >> val;
        tree.add_edge(i+1, v, val);
    }

    vector<int> ans(n+1);
    tree.build(1);

    for (int i = 1; i <= n; i++) {
        tree.accu[i]++;
        int k = i, val = apples[i];
        int mx = -1, mn = 1e10;
        for (int j = 29; j >= 0; j--) {
            if (tree.f[k][j] == 0) continue;
            if (max(mx, tree.mx[k][j]) - min(mn, tree.mn[k][j]) <= val) {
                mx = max(mx, tree.mx[k][j]);
                mn = min(mn, tree.mn[k][j]);
                k = tree.f[k][j];
            }
        }
        tree.accu[tree.f[k][0]]--;
    }

    ans = tree.make();

    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        run_case();
        cout << '\n';
    }
    return 0;
}