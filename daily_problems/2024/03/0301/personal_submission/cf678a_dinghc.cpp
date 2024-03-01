#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> covers[2] { vector<int>(), vector<int>() };
    auto bipartite = [&] () -> bool {
        vector<int> color(n, -1);
        bool is_bipartite = true;
        queue<int> q;
        for (int st = 0; st < n; ++st) {
            if (color[st] == -1) {
                q.push(st);
                color[st] = 0;
                while (!q.empty()) {
                    int v = q.front(); q.pop();
                    if (g[v].empty()) continue;
                    covers[color[v]].push_back(v + 1);
                    for (int u : g[v]) {
                        if (color[u] == -1) {
                            color[u] = color[v] ^ 1;
                            q.push(u);
                        } else {
                            is_bipartite &= color[u] != color[v];
                        }
                    }
                }
            }
        }

        return is_bipartite;
    };
    
    if (bipartite()) {
        cout << covers[0].size() << "\n";
        for (auto& u : covers[0]) {
            cout << u << " ";
        }
        cout << "\n";
        cout << covers[1].size() << "\n";
        for (auto& u : covers[1]) {
            cout << u << " ";
        }
        cout << "\n";
    } else {
        cout << "-1\n";
    }

    return 0;
}
