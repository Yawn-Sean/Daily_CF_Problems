#include <bits/stdc++.h>

using namespace std;
using int64 = long long;
constexpr int MXN = 3e5 + 5;

vector<int> g[MXN];
vector<pair<int, int>> queries[MXN];
int64 values[MXN];

struct seg_tree {
    int n;
    vector<int64> t;

    seg_tree(int n) : n(n), t(4 * n, 0) {}

    void update(int v, int l, int r, int L, int R, int64 add) {
        if (L >= R) return;
        if (l == L && r == R) {
            t[v] += add;
            return;
        }
        int m = (l + r) >> 1;
        update(v * 2 + 1, l, m, L, min(m, R), add);
        update(v * 2 + 2, m, r, max(m, L), R, add);
    }

    int64 query(int v, int l, int r, int pos) {
        if (l + 1 == r) {
            return t[v];
        }
        int m = (l + r) >> 1;
        if (pos < m) {
            return t[v] + query(v * 2 + 1, l, m, pos);
        } else {
            return t[v] + query(v * 2 + 2, m, r, pos);
        }
    }

    void update(int l, int r, int add) {
        update(0, 0, n, l, r, add);
    }

    int64 query(int pos) {
        return query(0, 0, n, pos);
    }
};

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int v, d, x;
        cin >> v >> d >> x;
        v--;
        queries[v].emplace_back(d, x);
    }
    
    seg_tree st(n);
    function<void(int, int, int)> dfs = [&] (int u, int pa, int h) {
        for (auto& [d, x] : queries[u]) st.update(h, min(n, h + d + 1), x);
        values[u] = st.query(h);
        for (auto& v : g[u]) {
            if (v == pa) continue;
            dfs(v, u, h + 1);
        }
        for (auto& [d, x] : queries[u]) st.update(h, min(n, h + d + 1), -x);
    };
    
    dfs(0, -1, 0);
    for (int i = 0; i < n; i++) {
        cout << values[i] << " ";
    }
    cout << "\n";

    return 0;
}
