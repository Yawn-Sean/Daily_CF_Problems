#include <bits/stdc++.h>
using namespace std;

struct DSU {
private:
    std::vector<int> f;
    std::vector<int> siz;
public:    
    explicit DSU(int n) noexcept : f(n), siz(n, 1) {
         std::iota(std::begin(f), std::end(f), 0); 
    }
    int leader (int x) noexcept {
        while (x != f[x]) {
            f[x] = f[f[x]];
            x = f[x];
        }
        return x;
    }
    bool merge(int x, int y) noexcept {
        x = leader(x);
        y = leader(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    bool same(int x, int y) noexcept { return leader(x) == leader(y); }
    int size(int x) noexcept { return siz[leader(x)]; }
};

void solve() {
    int n, m;
    std::cin >> n >> m;

    DSU dsu(n * 2);
    vector<vector<pair<int, int>>> tree(n);
    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < n - 1; ++i) {
        int x, y, v;
        cin >> x >> y >> v;
        --x; --y;
        edges.emplace_back(x, y, v);
        tree[x].emplace_back(x, v);
        tree[y].emplace_back(y, v);
        if (v != -1) {
            if (__builtin_popcount(v) & 1) {
                dsu.merge(x, y + n);
                dsu.merge(x + n, y);
            } else {
                dsu.merge(x, y);
                dsu.merge(x + n, y + n);
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        int x, y, p;
        cin >> x >> y >> p;
        --x; --y;
        if (p == 1) {
            dsu.merge(x + n, y);
            dsu.merge(x, y + n);
        } else {
            dsu.merge(x, y);
            dsu.merge(x + n, y + n);
        }
    }

    for (int i = 0; i < n; ++i) {
        if (dsu.same(i, i + n)) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";

    for (int i = 1; i < n; ++i) {
        if (dsu.leader(i) == dsu.leader(0) || dsu.leader(i + n) == dsu.leader(0)) {
            continue;
        }
        dsu.merge(0, i);
        dsu.merge(0 + n, i + n);
    }

    for (int i = 0; i < n - 1; ++i) {
        auto[x, y, v] = edges[i];
        if (v == -1) {
            if (dsu.leader(x) == dsu.leader(y)) {
                v = 0;
            } else {
                v = 1;
            }
        }
        cout << x + 1 << " " << y + 1 << " " << v << endl;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 0;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}