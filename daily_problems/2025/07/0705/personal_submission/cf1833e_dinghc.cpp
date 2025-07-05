#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        vector<vector<int>> a(n);
        set<pair<int, int>> edges;
        for (int i = 0, x; i < n; i++) {
            scanf("%d", &x);
            int u = x - 1, v = i;
            if (u > v) swap(u, v);
            auto p = make_pair(u, v);
            if (edges.find(p) == edges.end()) {
                a[u].push_back(v);
                a[v].push_back(u);
                edges.insert(p);
            }
        }
        int cycles = 0, chains = 0;
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            bool is_cycle = false;
            for (auto u : a[i]) {
                int p = i;
                while (u != i) {
                    vis[u] = 1;
                    bool has_next = false;
                    for (auto& v : a[u]) if (v != p) {
                        p = u;
                        u = v;
                        has_next = true;
                        break;
                    }
                    if (!has_next) break;
                }
                if (u == i) is_cycle = true;
            }
            if (is_cycle) cycles += 1;
            else chains += 1;
            vis[i] = 1;
        }
        printf("%d %d\n", cycles + min(chains, 1), cycles + chains);
    }
    return 0;
}

