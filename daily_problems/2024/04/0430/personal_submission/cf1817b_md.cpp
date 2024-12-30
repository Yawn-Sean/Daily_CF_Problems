// 0430
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

void solve() {
    int n, m;
    std::cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> path;
    deque<bool> visited(n, false);

    auto cout_path = [](int u, int v) {
        cout << u + 1 << ' ' << v + 1 << endl;
    };

    auto find_cycle = [&](int next, int source) -> bool {
        vector<int> fish;
        deque<bool> cycle(n, false);
        for (auto x : path) {
            cycle[x] = true;
        }

        for (int nnext : graph[next]) {
            if (!cycle[nnext]) {
                fish.push_back(nnext);
            }
        }

        if (size(fish) < 2) {
            return false;
        }

        cout << "Yes\n";
        cout << size(path) + 2 << endl;
        for (int i = 1; i < size(path); ++i) {
            cout_path(path[i - 1], path[i]);
        }
        cout_path(source, path.back());
        for (int i = 0; i < min(2, static_cast<int>(size(fish))); ++i) {
            cout_path(source, fish[i]);
        }
        return true;
    };

    auto dfs = [&](auto self, int cur, int parent, int source) -> bool {
        path.push_back(cur);
        visited[cur] = true;
        for (int next : graph[cur]) {
            if (next == parent) {
                continue;
            }
            
            if (next == source) {
                if (find_cycle(next, source)) {
                    return true;
                }
            }
            
            if (!visited[next]) {
                if (self(self, next, cur, source)) {
                    return true;
                }
            }
        }
        path.pop_back();
        return false;
    };

    for (int u = 0; u < n; ++u) {
        if (size(graph[u]) >= 4) {
            path.clear();
            visited.assign(n, false);
            if (dfs(dfs, u, -1, u)) {
                return;
            }
        }
    }
    cout << "No\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 0;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}