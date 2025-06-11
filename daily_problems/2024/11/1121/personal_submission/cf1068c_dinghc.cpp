#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> ans(n + 1, vector<pair<int, int>>());
    for (int i = 1; i <= n; i++) {
        ans[i].emplace_back(i, i);
    }
    for (int i = 0, y = n + 1, u, v; i < m; i++, y++) {
        cin >> u >> v;
        ans[u].emplace_back(u, y);
        ans[v].emplace_back(v, y);
    }
    for (int i = 1; i <= n; i++) {
        auto& rs = ans[i];
        cout << rs.size() << "\n";
        for (auto&[x, y] : rs) {
            cout << x << " " << y << "\n";
        }
    }
    return 0;
}

