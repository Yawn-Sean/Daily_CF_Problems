/**
 * https://codeforces.com/problemset/problem/29/D
 * D. Ant on the Tree
 * Solver: nhant
 * 2025-04-10 05:26:57
 * Submission: https://codeforces.com/problemset/submission/29/314813369
 */
#include <bits/stdc++.h>

using namespace std;

const int ROOT = 1;
vector<vector<int>> adj;
vector<bitset<301>> leaves;
vector<int> reqLeaf;
int nextLeafI;
vector<bool> visited;
vector<int> path;

void dfs1(int u, int p) {
    if (adj[u].size() == 1 && u != ROOT) {
        leaves[u][u] = true;
        return;
    }
    for (int v : adj[u]) {
        if (v != p) {
            dfs1(v, u);
            leaves[u] |= leaves[v];
        }
    }
}

void dfs2(int u, int p) {
    if (nextLeafI == -1) return;
    visited[u] = true;
    path.push_back(u);
    if (adj[u].size() == 1 && u != ROOT) {
        if (u == reqLeaf[nextLeafI]) {
        // if (leaves[u][reqLeaf[nextLeafI]]) { // either above or this are ok
            nextLeafI++;
        } else {
            nextLeafI = -1;
        }
        return;
    }
    bool explored = true;
    while (explored) {
        explored = false;
        for (int v : adj[u]) {
            if (v != p && !visited[v] && leaves[v][reqLeaf[nextLeafI]]) {
                explored = true;
                dfs2(v, u);
                path.push_back(u);
            }
        }
    }
}


void solve() {
    int n;
    cin >> n;
    adj = vector<vector<int>>(n + 1, vector<int>());
    leaves = vector<bitset<301>>(n + 1, bitset<301>());
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1, -1);
    int k = (int)leaves[1].count();
    reqLeaf = vector<int>(k);
    for (int& v : reqLeaf)
        cin >> v;
    nextLeafI = 0;
    visited = vector<bool>(n + 1);
    dfs2(1, -1);
    if (nextLeafI != k) {
        cout << "-1\n";
    } else {
        for (int v : path)
            cout << v << " ";
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
