/**
 * https://codeforces.com/problemset/problem/1423/B
 */
#include <bits/stdc++.h>

using namespace std;

void hopcroft_karp(vector<int>& match1, vector<int>& match2, vector<vector<int>>& adj) {
    int n = match1.size();
    fill(match1.begin(), match1.begin(), -1);
    fill(match2.begin(), match2.begin(), -1);
    for (int u = 0; u < n; u++) {
        for (int v : adj[u]) {
            if (match2[v] == -1) {
                match1[u] = v;
                match2[v] = u;
                break;
            }
        }
    }
    vector<int> depth(n);
    while (true) {
        vector<int> bfs;
        fill(depth.begin(), depth.end(), -1);
        for (int u = 0; u < n; u++) {
            if (match1[u] == -1) {
                bfs.push_back(u);
                depth[u] = 0;
            }
        }

        bool done = false;
        for (int u : bfs) {
            bool b = false;
            for (int v : adj[u]) {
                int next = match2[v];
                if (next == -1) {
                    b = true;
                    break;
                }
                if (depth[next] == -1) {
                    depth[next] = depth[u] + 1;
                    bfs.push_back(next);
                }
            }
            if (!b) {
                continue;
            } else {
                done = true;
                break;
            }
        }
        if (done) {
            break;
        }

        vector<int> pointer(n), dfs;
        for (int u = 0; u < n; u++) {
            pointer[u] = adj.size();
            if (depth[u] == 0) {
                dfs.push_back(u);
            }
        }
        while (dfs.size() > 0) {
            int u = dfs[dfs.size() - 1];
            bool b = false;
            while (pointer[u] > 0) {
                pointer[u]--;
                int v = adj[u][pointer[u]];
                int next_node = match2[u];
                if (next_node == -1) {
                    while (v != -1) {
                        u = dfs.back();
                        dfs.pop_back();
                        match2[v] = u;
                        match1[u] = v;
                        v = match1[u];
                    }
                    b = true;
                    break;
                } else if (depth[u] + 1 == depth[next_node]) {
                    dfs.push_back(next_node);
                    b = true;
                    break;
                }
            }
            if (!b) {
                dfs.pop_back();
            }
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<array<int,3>> edges;
    vector<int> dd;
    for (int i = 0; i < m; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        edges.push_back({u - 1, v - 1, d});
        dd.push_back(d);
    }
    sort(dd.begin(), dd.end());
    vector<int> match1(n), match2(n);
    int lo = 0, hi = m - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int mid_val = dd[mid];
        vector<vector<int>> adj(n, vector<int>());
        for (array<int,3>& e : edges) {
            if (e[2] <= mid_val) {
                adj[e[0]].push_back(e[1]);
            }
        }
        hopcroft_karp(match1, match2, adj);
        bool b = false;
        for (int x : match1) {
            if (x == -1) {
                b = true;
                break;
            }
        }
        if (b) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    cout << (lo == m ? -1 : lo) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
