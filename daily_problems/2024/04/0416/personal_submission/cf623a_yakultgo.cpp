#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1, vector<int>(n + 1));
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = adj[v][u] = 1;
    }
    // 只有a和c之间没有连边，因此看看该图的补图是不是二分图
    vector<int> g[n + 1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j && !adj[i][j]) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    vector<int> color(n + 1, -1);
    function<bool(int, int)> dfs = [&](int u, int c) {
        color[u] = c;
        for (int v : g[u]) {
            if (color[v] == -1) {
                if (!dfs(v, c ^ 1)) {
                    return false;
                }
            } else if (color[v] == c) {
                return false;
            }
        }
        return true;
    };
    for (int i = 1; i <= n; i++) {
        // 跳过孤立点，即b点
        if (color[i] == -1 && !g[i].empty()) {
            if (!dfs(i, 0)) {
                cout << "No" << endl;
                return;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (adj[i][j] && color[i] + color[j] == 1) {
                cout << "No" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++) {
        if (color[i] == -1)
            cout << "b";
        else {
            cout << (color[i] == 0 ? "a" : "c");
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}