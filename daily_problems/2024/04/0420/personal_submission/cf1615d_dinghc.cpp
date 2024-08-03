#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<pair<int, int>>> g(n, vector<pair<int, int>>());
        vector<vector<pair<int, int>>> tree(n, vector<pair<int, int>>());
        for (int i = 0, u, v, w; i < n - 1; i++) {
            cin >> u >> v >> w;
            u--, v--;
            tree[u].emplace_back(v, w);
            tree[v].emplace_back(u, w);
            if (w != -1) {
                int cnt = __builtin_popcount(w) % 2;
                g[u].emplace_back(v, cnt);
                g[v].emplace_back(u, cnt);
            }
        }
        for (int i = 0, u, v, p; i < m; i++) {
            cin >> u >> v >> p;
            u--, v--;
            g[u].emplace_back(v, p);
            g[v].emplace_back(u, p);
        }

        auto check = [&] () -> bool {
            bool res = true;
            vector<int> colors(n, -1);
            queue<int> q;
            for (int u = 0; u < n && res; ++u) {
                if (colors[u] == -1) {
                    q.push(u);
                    colors[u] = 0;
                    while (!q.empty()) {
                        int v = q.front(); q.pop();
                        for (auto& [w, p] : g[v]) {
                            if (colors[w] == -1) {
                                q.push(w);
                                colors[w] = colors[v] ^ p;
                            } else {
                                res &= colors[w] ^ colors[v] ^ p == 0;
                            }
                        }
                    }
                }
            }
            if (res) {
                for (int u = 0; u < n; u++) {
                    for (auto& [v, w] : tree[u]) {
                        if (w == -1) {
                            w = colors[v] ^ colors[u];
                        }
                    }
                }
            }
            return res;
        };
    
        if (check()) {
            cout << "Yes\n";
            for (int u = 0; u < n; u++) {
                for (auto& [v, w] : tree[u]) {
                    if (v > u) {
                        cout << u+1 << " " << v+1 << " " << w << "\n";
                    }
                }
            }
        } else {
            cout << "No\n";
        }
    }

    return 0;
}

