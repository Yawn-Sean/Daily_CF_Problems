#include <bits/stdc++.h>

using namespace std;

struct dsu {
    int _n;
    vector<int> parent_or_size;
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {
    }
    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }
    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }
    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }
    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }
};

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> a(n);
    for (auto& x : a) {
        scanf("%d", &x);
    }
    vector<pair<int, int>> edges(m);
    for (auto& [u, v] : edges) {
        scanf("%d %d", &u, &v);
        u -= 1;
        v -= 1;
    }
    vector<vector<int>> ans(n, vector<int>(n, 0));
    for (int i = 0; i < 30; i++) {
        dsu dsu_(n);
        for (auto& [u, v] : edges) {
            if ((a[u] >> i & 1) && (a[v] >> i & 1)) {
                dsu_.merge(u, v);
            }
        }
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (u == v || dsu_.same(u, v)) ans[u][v] = 1;
            }
        }
    }
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            printf("%d", ans[u][v]);
        }
        printf("\n");
    }
    return 0;
}

