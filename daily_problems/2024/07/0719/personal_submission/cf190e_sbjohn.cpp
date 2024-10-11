#include <bits/stdc++.h>

//#define DEBUG
#ifndef  DEBUG
#pragma GCC optimize("O3")
#endif
using namespace std;


using i64 = long long;
using pii = pair<int, int>;
//using u32 = unsigned;
constexpr int inf = INT32_MAX >> 1;
//constexpr i64 inf = INT64_MAX >> 1;
using vi = vector<int>;
using vl = vector<i64>;
using vb = vector<bool>;
#define all(x) (x).begin(),(x).end()
constexpr int mod = 1e9 + 7;

struct DSU {
    vi fa_or_size;
    // -1 * size or father
    // -5 root and size is 5     6 father is 6
    int _n;

    DSU(int n) : _n(n) {
//        assert(_n > 0);
        fa_or_size = vi(_n, -1);
    }

    void init(int n) {
        _n = n;
        fa_or_size.resize(_n);
        fa_or_size.assign(_n, -1);
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    int find(int x) {
//        assert(x >= 0 && x < _n);
        if (fa_or_size[x] < 0) return x;
        return fa_or_size[x] = find(fa_or_size[x]);
    }

    int size(int x) {
//        assert(x >= 0 && x < _n);
        return -fa_or_size[find(x)];
    }

    bool merge(int x, int y) {
//        assert(x >= 0 && x < _n);
//        assert(y >= 0 && y < _n);
        int rx = find(x), ry = find(y);
        int sx = -fa_or_size[rx], sy = -fa_or_size[ry];
        if (rx != ry) {
            if (sx < sy) swap(rx, ry);
            fa_or_size[ry] = rx;
            fa_or_size[rx] = -(sx + sy);
            return true;
        } else {
            return false;
        }
    }

};
//稠密图 求 联通分量
// 先求一个deg最大的点 直接边构成的联通分量
// 剩下孤立的点在暴力算
// time O(n+m)
void solve() {
    int n, m;
    cin >> n >> m;
    if (m == 0) {
        cout << 1 << endl;
        cout << n << endl;
        for (int i = 0; i < n; ++i)
            cout << i + 1 << " \n"[i == n - 1];
        return;
    }
    DSU dsu(n);
    vector g(n, vi());
    vi deg(n);
    vb vis(n, false);
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    int mxp = min_element(all(deg)) - deg.begin();
    for (int i = 0; i < n; ++i)
        sort(all(g[i]));

    auto dfs = [&](auto &&self, int x) -> void {
//        if(vis[x]) return;
        vis[x] = true;
        for (int i = 0, j = 0; i < n; i++) {
            if (!g[x].empty() && j < g[x].size() && i == g[x][j]) {
                j++;
                continue;
            }
            dsu.merge(i, x);
            if (!vis[i]) self(self, i);
        }
    };
    vis[mxp] = true;
    for (int i = 0, j = 0; i < n; i++) {
        if (!g[mxp].empty() && j < g[mxp].size() && i == g[mxp][j]) {
            j++;
            continue;
        }
        dsu.merge(mxp, i);
        vis[i] = true;
    }
    for (int i = 0; i < n; ++i) {
        if (vis[i]) continue;
        dfs(dfs, i);
    }
    unordered_map<int, vi> mp;
    for (int i = 0; i < n; ++i) {
        int rt = dsu.find(i);
        mp[rt].push_back(i + 1);
    }
    for (int i = 0; i < n; ++i) assert(vis[i]);
    cout << mp.size() << endl;
    for (auto [_, vc]: mp) {
        cout << vc.size();
        for (auto v: vc)
            cout << ' ' << v;
        cout << endl;
    }
}

int main() {
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
//    cin >> t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}






