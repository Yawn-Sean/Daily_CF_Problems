#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 inf = 1e18;
i64 mod = 1e9+9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<set<int>> path(n + 1);
    for (int i = 0; i < 2 * n; i++) {
        int u, v;
        cin >> u >> v;
        path[u].insert(v);
        path[v].insert(u);
    }

    int mx = 0;
    for (int i = 0; i < n; i++) {
        mx = max(mx, (int)path[i].size());
    }

    if (mx > 4) {
        cout << -1;
        return 0;
    } else {
        for (auto& u: path[1]) {
            for (auto& v: path[1]) {
                if (u != v) {
                    vector<int> vis(n + 1);
                    vector<int> cycle{1, u, v};
                    vis[1] = 1; vis[u] = 1;
                    vis[v] = 1;
                    for (int i = 0; i < n - 3; i++) {
                        int x = cycle[(int)cycle.size()-2];
                        int y = cycle[(int)cycle.size()-1];
                        for (auto&z: path[y]) {
                            if (!vis[z] && path[z].find(x) != path[z].end()) {
                                vis[z] = 1;
                                cycle.push_back(z);
                                break;
                            }
                        }
                    }

                    int a = cycle[(int)cycle.size() - 2], b = cycle[(int)cycle.size() - 1];
                    if (cycle.size() == n && path[a].find(cycle[0]) != path[a].end() && path[b].find(cycle[0]) != path[b].end()) {
                        for (auto&x: cycle) {
                            cout << x << ' ';
                        }
                        return 0;
                    }
                }
            }
        }
    }
    cout << -1;

    return 0;
}
