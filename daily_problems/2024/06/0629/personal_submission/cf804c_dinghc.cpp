#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<set<int>> types(n, set<int>());
    for (int i = 0, si; i < n; i++) {
        cin >> si;
        for (int j = 0, type; j < si; j++) {
            cin >> type;
            type--;
            types[i].insert(type);
        }
    }
    vector<vector<int>> g(n, vector<int>());
    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> colors(m, 0);
    function<void(int, int)> dfs = [&] (int curr, int prev) {
        set<int> forbidden;
        if (prev != -1) {
            for (auto& t : types[curr]) {
                if (types[prev].contains(t)) {
                    forbidden.insert(colors[t]);
                }
            }
        }
        int avail_color = 1;
        for (auto& t : types[curr]) {
            if (colors[t] == 0) {
                while (forbidden.contains(avail_color)) {
                    avail_color++;
                }
                colors[t] = avail_color++;
            }
        }
        for (auto& u : g[curr]) {
            if (u != prev) {
                dfs(u, curr);
            }
        }
    };
    dfs(0, -1);
    cout << max(ranges::max(colors), 1) << "\n";
    for (auto& c : colors) {
        cout << max(c, 1) << " ";
    }
    cout << "\n";
    return 0;
}

