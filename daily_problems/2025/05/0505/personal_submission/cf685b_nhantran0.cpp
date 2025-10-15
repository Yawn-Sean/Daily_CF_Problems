/*
 https://codeforces.com/problemset/problem/685/B
 B. Kay and Snowflake
 Solver: nhant
 2025-05-06 09:21:55
 https://codeforces.com/problemset/submission/685/318569422
*/
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> child;
vector<int> sz, centroid, pa;

void dfs(int u) {
    int tree_sz = 1, max_child_sz = 0, max_child = 0;
    for (int v : child[u]) {
        dfs(v);
        if (sz[v] > max_child_sz) {
            max_child_sz = sz[v];
            max_child = v;
        }
        tree_sz += sz[v];
    }
    if (max_child == 0) {
        centroid[u] = u;
    } else {
        int c = centroid[max_child];
        while (c != u && sz[c] * 2 < tree_sz) {
            c = pa[c];
        }
        centroid[u] = c;
    }
    sz[u] = tree_sz;
}

void solve() {
    int n, q;
    cin >> n >> q;
    child = vector<vector<int>>(n + 1, vector<int>());
    sz = vector<int>(n + 1);
    centroid = vector<int>(n + 1);
    pa = vector<int>(n + 1);
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        child[p].push_back(i);
        pa[i] = p;
    }
    dfs(1);
    while (q--) {
        int v;
        cin >> v;
        cout << centroid[v] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
