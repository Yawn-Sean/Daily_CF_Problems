#include <bits/stdc++.h>
#include <cmath>

#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
// #define double long double
// #define acos acosl
// #define sqrt sqrtl
// #define sin sinl
// #define cos cosl
#define pii pair<int, int>
using namespace std;
const int N = 2e5 + 5, MOD = 1e9 + 7;
const double PI = acos(-1);
void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int total = (a + 1) * (b + 1) * (c + 1);
    vector<int> blocked(total);
    auto f = [&](int x, int y, int z) -> int {
        return (z - 1) * (a * b) + (x - 1) * b + y - 1;
    };
    int k;
    cin >> k;
    while (k--) {
        int x, y, z;
        cin >> x >> y >> z;
        blocked[f(x, y, z)] = 1;
    }
    vector<vector<int>> adj(total);
    vector<array<int, 3>> dirs;
    for (int i = -2; i <= 2; i++) {
        for (int j = -2; j <= 2; j++) {
            if (abs(i) + abs(j) == 3) {
                dirs.push_back({0, i, j});
                dirs.push_back({i, 0, j});
                dirs.push_back({i, j, 0});
            }
        }
    }
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            for (int k = 1; k <= c; k++) {
                if (blocked[f(i, j, k)])
                    continue;
                if (i + j + k & 1) {
                    for (auto [dx, dy, dz] : dirs) {
                        int x = i + dx;
                        int y = j + dy;
                        int z = k + dz;
                        if (x >= 1 && x <= a && y >= 1 && y <= b && z >= 1 &&
                            z <= c && !blocked[f(x, y, z)]) {
                            int u = f(i, j, k);
                            int v = f(x, y, z);
                            adj[u].push_back(v);
                        }
                    }
                }
            }
        }
    }
    vector<int> match(total, -1);
    int res = 0;
    vector<int> vis(total);
    auto dfs = [&](auto dfs, int u) -> int {
        for (int v : adj[u]) {
            if (vis[v])
                continue;
            vis[v] = 1;
            if (match[v] == -1 || dfs(dfs, match[v])) {
                match[v] = u;
                match[u] = v;
                return 1;
            }
        }
        return 0;
    };
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            for (int k = 1; k <= c; k++) {
                if (i + j + k & 1) {
                    if (!blocked[f(i, j, k)]) {
                        fill(vis.begin(), vis.end(), 0);
                        if (dfs(dfs, f(i, j, k)))
                            res++;
                    }
                }
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            for (int k = 1; k <= c; k++) {
                cnt += !blocked[f(i, j, k)];
            }
        }
    }
    cout << cnt - res << endl;
}

signed main() {
    IOS;
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}