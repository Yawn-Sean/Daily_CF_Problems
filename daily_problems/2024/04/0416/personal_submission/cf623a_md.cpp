#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        graph[i][i] = 1;
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    vector<vector<int>> inv_graph = graph;
    for (int i = 0; i < n; ++i) {
        transform(begin(graph[i]), end(graph[i]), begin(inv_graph[i]), [](int x) { return 1 - x; });
    }

    vector<int> ret(n, -1);
    auto dfs = [&](auto self, int cur, int parent, int color) -> bool {
        ret[cur] = color;
        for (int i = 0; i < n; ++i) {
            if (i == parent) { continue; }
            if (inv_graph[cur][i]) {
                if (ret[i] == ret[cur]) { return false; }
                if (ret[i] != -1) { continue; }
                if (!self(self, i, cur, 1 - color)) {
                    return false;
                }
            }
        }
        return true;
    };

    for (int i = 0; i < n; ++i) {
        if (ret[i] == -1 && (count(begin(inv_graph[i]), end(inv_graph[i]), 1) > 0)) {
            if (!dfs(dfs, i, -1, 0)) {
                cout << "No\n" << endl;
                return 0;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (graph[i][j]) {
                if ((ret[i] ^ ret[j]) == 1) {
                    cout << "No\n";
                    return 0;
                }
            }
        }
    }

    cout << "Yes\n";
    string str_ret;
    transform(begin(ret), end(ret), back_inserter(str_ret), [](int x) { 
        if (x == -1) { return 'b'; }
        if (x == 0) { return 'a'; }
        return 'c';
    });

    cout << str_ret << endl;
    return 0;
}