#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> g(n, vector<pair<int, int>>());
    for (int i = 0, u, v; i < m; i++) {
        string clr;
        cin >> u >> v >> clr;
        g[u - 1].emplace_back(v - 1, clr == "B" ? 0 : 1);
        g[v - 1].emplace_back(u - 1, clr == "B" ? 0 : 1);
    }

    auto check = [&] (int clr, vector<int>& vertices) -> bool {
        bool res = true;
        vector<int> colors(n, -1);
        vector<array<vector<int>, 2>> groups;
        queue<int> q;
        for (int u = 0; u < n && res; ++u) {
            if (colors[u] == -1) {
                array<vector<int>, 2> arr{vector<int>(), vector<int>()};
                q.push(u);
                colors[u] = 0;
                arr[0].push_back(u);
                while (!q.empty()) {
                    int v = q.front(); q.pop();
                    for (auto& [w, c] : g[v]) {
                        if (colors[w] == -1) {
                            q.push(w);
                            colors[w] = colors[v] ^ c ^ clr;
                            arr[colors[w]].push_back(w);
                        } else {
                            res &= colors[w] ^ colors[v] ^ c ^ clr == 0;
                        }
                    }
                }
                groups.emplace_back(arr);
            }
        }
        if (res) {
            for (auto& arr : groups) {
                if (arr[0].size() > arr[1].size()) arr[0].swap(arr[1]);
                copy(arr[0].begin(), arr[0].end(), back_inserter<>(vertices));
            }
        }
        return res;
    };

    vector<int> vertices0, vertices1;
    bool is_bipart0 = check(0, vertices0);
    bool is_bipart1 = check(1, vertices1);
    if (!is_bipart0 && !is_bipart1) {
        cout << "-1\n";
    } else {
        if (!is_bipart0) {
            vertices0.swap(vertices1);
        } else if (is_bipart1 && vertices0.size() > vertices1.size()) {
            vertices0.swap(vertices1);
        }
        cout << vertices0.size() << "\n";
        for (auto& v : vertices0) {
            cout << v + 1 << " ";
        }
    }

    return 0;
}

