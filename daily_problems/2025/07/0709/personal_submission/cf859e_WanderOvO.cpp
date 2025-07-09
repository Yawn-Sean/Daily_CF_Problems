/*
写的是 python，但是递归遍历会 RE，于是直接使用 deepseek 转成 C++ 通过
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX_N = 2e5 + 10; 

vector<vector<int>> e(MAX_N), rev_e(MAX_N);
vector<int> d(MAX_N, 0);
vector<bool> vis(MAX_N, false);
int n;

long long qpow(long long a, long long b) {
    long long res = 1, base = a;
    while (b > 0) {
        if (b & 1) {
            res = res * base % MOD;
        }
        base = base * base % MOD;
        b >>= 1;
    }
    return res % MOD;
}

void get_ring_nodes(int u, vector<int>& nodes) {
    vis[u] = true;
    nodes.push_back(u);
    for (int v : rev_e[u]) {
        if (d[v] > 0 && !vis[v]) {
            get_ring_nodes(v, nodes);
        }
    }
}

void dfs(int u) {
    vis[u] = true;
    for (int v : rev_e[u]) {
        if (d[v] == 0) {
            dfs(v);
        }
    }
}

int get_tree_size(int u) {
    vis[u] = true;
    int size = 1;
    for (int v : rev_e[u]) {
        if (d[v] == 0) {
            size += get_tree_size(v);
        }
    }
    return size;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        d[v]++;
        rev_e[v].push_back(u);
    }

    queue<int> q;
    for (int i = 1; i <= 2 * n; ++i) {
        if (d[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : e[u]) {
            d[v]--;
            if (d[v] == 0) {
                q.push(v);
            }
        }
    }

    long long res = 1;

    for (int i = 1; i <= 2 * n; ++i) {
        if (!vis[i] && d[i] > 0) {
            vector<int> nodes;
            get_ring_nodes(i, nodes);
            if (nodes.size() > 1) {
                res = res * 2 % MOD;
            }
            for (int u : nodes) {
                dfs(u);
            }
        }
    }

    for (int i = 1; i <= 2 * n; ++i) {
        if (!vis[i]) {
            int u = i;
            while (!e[u].empty()) {
                u = e[u][0];
            }
            int tree_size = get_tree_size(u);
            res = res * tree_size % MOD;
        }
    }

    cout << res << endl;

    return 0;
}
