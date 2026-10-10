#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
namespace rgs = ranges;

struct DSU {
    vector<int> fa, p, e, f;

    DSU(int n) {
        fa.resize(n + 1);
        iota(fa.begin(), fa.end(), 0);
        p.resize(n + 1, 1);
        e.resize(n + 1);
        f.resize(n + 1);
    }
    int get(int x) {
        while (x != fa[x]) {
            x = fa[x] = fa[fa[x]];
        }
        return x;
    }
    bool merge(int x, int y) {
        if (x == y)
            f[get(x)] = 1;
        x = get(x), y = get(y);
        e[x]++;
        if (x == y)
            return false;
        if (x < y)
            swap(x, y);
        fa[y] = x;
        f[x] |= f[y], p[x] += p[y], e[x] += e[y];
        return true;
    }
    bool same(int x, int y) { return get(x) == get(y); }
    bool F(int x) { return f[get(x)]; }
    int size(int x) { return p[get(x)]; }
    int E(int x) { return e[get(x)]; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> odd(n + 1, 0);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        odd[u] ^= 1, odd[v] ^= 1;
    }

    DSU du(n + 1);
    vector<vector<int>> edge(n + 1);
    for (int i = 1; i <= k; i++) {
        int u, v;
        cin >> u >> v;
        if (du.same(u, v)) {
            continue;
        }
        edge[u].push_back(v);
        edge[v].push_back(u);
        du.merge(u, v);
    }

    vector<array<int, 2>> ver;
    auto dfs = [&](this auto& dfs, int u, int fa) -> int {
        int cur = odd[u];
        for (const auto& v : edge[u]) {
            if (v == fa) {
                continue;
            }
            cur ^= dfs(v, u);
        }

        if (cur) {
            ver.push_back({u, fa});
        }
        return cur;
    };

    for (int i = 1; i <= n; i++) {
        if (du.get(i) == i && dfs(i, 0)) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    cout << ver.size() << "\n";
    for (const auto& [x, y] : ver) {
        cout << x << ' ' << y << "\n";
    }
    return 0;
}