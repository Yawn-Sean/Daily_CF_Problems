/*
 https://codeforces.com/problemset/problem/208/C
 C. Police Station
 Solver: nhant
 2025-05-13 17:21:36
 https://codeforces.com/problemset/submission/208/319494567, O(N + M)
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int64_t> f(n + 1), g(n + 1);
    int DIST_MAX = 102;
    vector<int> fd(n + 1, DIST_MAX), gd(n + 1, DIST_MAX);
    queue<int> q;
    q.push(1);
    fd[1] = 0;
    f[1] = 1;
    while (q.size() > 0) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (fd[v] > fd[u] + 1) {
                fd[v] = fd[u] + 1;
                q.push(v);
            }
            if (fd[v] == fd[u] + 1) {
                f[v] += f[u];
            }
        }
    }
    q.push(n);
    gd[n] = 0;
    g[n] = 1;
    while (q.size() > 0) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (gd[v] > gd[u] + 1) {
                gd[v] = gd[u] + 1;
                q.push(v);
            }
            if (gd[v] == gd[u] + 1) {
                g[v] += g[u];
            }
        }
    }
    double res = 1;
    for (int i = 2; i < n; i++) {
        if (fd[i] + gd[i] == fd[n]) {
            res = max(res, (double) f[i] * g[i] * 2 / f[n]);
        }
    }
    cout << fixed << setprecision(12) << res << '\n';
}
