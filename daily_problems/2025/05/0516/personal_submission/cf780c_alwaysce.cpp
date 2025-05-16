#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    /*
        树上染色问题 模板
    */
    int n;
    cin >> n;
    vector<vector<int>> path(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        path[u].push_back(v);
        path[v].push_back(u);
    }

    vector<int> colors(n);
    function<void(int,int)> dfs = [&](int u, int p) {
        // [1, l]
        int l = path[u].size() + 1;
        vector<int> used(l + 1, 0);
        if (colors[u] != 0 && colors[u] <= l) {
            used[colors[u]] = 1;
        }
        if (p >= 0 && colors[p] != 0 && colors[p] <= l) {
            used[colors[p]] = 1;
        }

        int idx = 1;
        for (auto&v: path[u]) {
            if (v == p) continue;
            while (idx <= l && used[idx]) { idx++; }
            used[idx] = 1;
            // assign color
            colors[v] = idx; 
            dfs(v, u);
        }
    };

    colors[0] = 1;
    dfs(0, -1);

    cout << *max_element(colors.begin(), colors.end()) << '\n';
    for (auto& u: colors) {
        cout << u << ' ';
    }
    cout << '\n';
    return 0;
}
