#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> fa, sz;
    DSU(int n = 0) {
        init(n);
    }
    void init(int n) {
        fa.resize(n);
        sz.assign(n, 1);
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int x) {
        if (fa[x] == x) return x;
        return fa[x] = find(fa[x]);
    }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if (sz[x] < sz[y]) swap(x, y);
        fa[y] = x;
        sz[x] += sz[y];
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> nums(n);
    for (auto &x : nums) cin >> x;

    vector<pair<int, int>> edges(m);
    for (auto &[u, v] : edges) {
        cin >> u >> v;
        --u; --v;
    }
    sort(edges.begin(), edges.end(),
        [&](const pair<int, int> &x, const pair<int, int> &y) {
            return max(nums[x.first], nums[x.second]) <
                   max(nums[y.first], nums[y.second]);
        });

    DSU uf(n);
    vector<vector<int>> path(2 * n - 1);
    vector<int> notes(n);
    iota(notes.begin(), notes.end(), 0);

    int pt = n;
    for (auto &[u, v] : edges) {
        int fu = uf.find(u);
        int fv = uf.find(v);
        if (fu != fv) {
            path[pt].push_back(notes[fu]);
            path[pt].push_back(notes[fv]);
            uf.merge(fu, fv);
            notes[uf.find(fu)] = pt;
            pt++;
        }
    }

    vector<int> val(2 * n - 1, 0);
    vector<int> sz(2 * n - 1, 0);

    auto dfs1 = [&](auto &&self, int u) -> void {
        if (u < n) {
            sz[u] = 1;
            val[u] = nums[u];
        }
        for (int v : path[u]) {
            self(self, v);
            sz[u] += sz[v];
            val[u] = max(val[u], val[v]);
        }
    };

    int root = 2 * n - 2;
    dfs1(dfs1, root);

    vector<long long> ans(2 * n - 1, 0);

    auto dfs2 = [&](auto &&self, int u) -> void {
        if (u < n) ans[u] += nums[u];
        for (int v : path[u]) {
            ans[v] = ans[u] + 1LL * (sz[u] - sz[v]) * val[u];
            self(self, v);
        }
    };

    dfs2(dfs2, root);

    for (int i = 0; i < n; i++) {
        cout << ans[i] << (i + 1 == n ? '\n' : ' ');
    }

    return 0;
}
