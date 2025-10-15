/**
 * https://codeforces.com/problemset/problem/813/C
 * C. The Tag Game
 * Solver: nhant
 * 2025-04-16 16:57:31
 * https://codeforces.com/problemset/submission/813/315808459
 */
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<int> da, db;

void dfs(int u, int p, int dist, vector<int>& dists) {
    dists[u] = dist;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, dist + 1, dists);
        }
    }
}

void solve() {
    int n, x;
    cin >> n >> x;
    x--;
    adj = vector<vector<int>>(n, vector<int>());
    da = vector<int>(n);
    db = vector<int>(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, -1, 0, da);
    dfs(x, -1, 0, db);
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (da[i] > db[i]) {
            res = max(res, da[i] * 2);
        }
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
