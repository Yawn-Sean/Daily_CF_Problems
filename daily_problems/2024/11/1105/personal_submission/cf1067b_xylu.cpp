#include <bits/stdc++.h>
using namespace std;

void solveB() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n);
    vector<int> d(n, 0), son(n, 0), deg(n, 0);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++, deg[v]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 1) {
            q.push(i);
            d[i] = 1;
        }
    }

    for (int t = 0; t <= k; t++) {
        if (q.empty()) return void(cout << "No\n");
        for (int i = q.size(); i; i--) {
            int u = q.front();
            deg[u] = -1;
            q.pop();
            if (t && son[u] < 3) return void(cout << "No\n");
            for (int v : g[u]) {
                if (deg[v] == -1) continue;
                deg[v]--, son[v]++;
                if (d[v] && d[v] != d[u] + 1) return void(cout << "No\n");
                d[v] = d[u] + 1;
                if (deg[v] == 1) q.push(v);
            }
        }
    }

    cout << (q.empty() ? "Yes" : "No") << '\n';
}

int main() {
    solveB();
    return 0;
}
