#include <bits/stdc++.h>

using namespace std;

enum class color {
    white, gray, black
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n);
    map<pair<int, int>, int> edges;
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        u--, v--;
        edges[{u, v}] = i;
        g[u].push_back(v);
    }

    // do topological sort
    list<int> ordering;
    vector<color> colors(n, color::white);
    function<void(int)> dfs = [&] (int u) {
        colors[u] = color::gray;
        for (auto& v : g[u]) {
            if (colors[v] == color::white) {
                dfs(v);
            }
        }
        colors[u] = color::black;
        ordering.push_front(u);
    };

    for (int u = 0; u < n; u++) {
        if (colors[u] == color::white) {
            dfs(u);
        }
    }

    int ans = -1;
    // DAG has a unique topological ordering <=> there is a directed edge between each pair of consecutive vertices in the topological order
    auto it = ordering.begin();
    int pre = *it;
    for (it++; it != ordering.end(); it++) {
        auto it_edg = edges.find({pre, *it});
        if (it_edg == edges.end()) {
            ans = -1;
            break;
        }
        ans = max(it_edg->second + 1, ans);
        pre = *it;
    }

    cout << ans << "\n";

    return 0;
}

