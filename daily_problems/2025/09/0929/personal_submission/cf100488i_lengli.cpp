#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, c;
    if (!(cin >> n >> m >> c)) return 0;

    vector<unordered_set<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v; --u; --v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    vector<int> color(n, 0);
    int cc = 0;

    set<int> rem;
    for (int i = 0; i < n; ++i) rem.insert(i);

    queue<int> q;
    while (!rem.empty()) {
        int s = *rem.begin();
        rem.erase(rem.begin());
        ++cc;
        color[s] = cc;
        q.push(s);

        while (!q.empty()) {
            int u = q.front(); q.pop();

            vector<int> grab; grab.reserve(64);
            for (auto it = rem.begin(); it != rem.end(); ) {
                int v = *it;
                if (!adj[u].count(v)) { 
                    grab.push_back(v);
                    it = rem.erase(it);
                } else {
                    ++it;
                }
            }
            for (int v : grab) {
                color[v] = cc;
                q.push(v);
            }
        }
    }

    if (cc > c) {
        cout << -1;
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            bool hasEdge = adj[i].count(j);
            bool sameCol = (color[i] == color[j]);
            if (hasEdge == sameCol) {
                cout << -1;
                return 0;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << color[i] << (i + 1 == n ? '\n' : ' ');
    }
    return 0;
}
