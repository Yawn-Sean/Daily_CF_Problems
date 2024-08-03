#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, i;
    while (cin >> n) {
        vector<int> a(n + 1);
        vector<int64_t> res(n + 1), d(n + 1);
        vector<pair<int64_t, int>> path;
        vector<pair<int, int>> e[n + 1];
        for (i = 1; i <= n; ++i) {
            cin >> a[i];
        }

        for (i = 2; i <= n; ++i) {
            int a, b;
            cin >> a >> b;
            e[a].emplace_back(b, i);
        }

        function<void(int)> Dfs = [&](int u) -> void {
            path.emplace_back(d[u], u);
            int cur = lower_bound(path.begin(), path.end(), make_pair(d[u] - a[u], -1)) - path.begin() - 1;
            if (cur >= 0) res[path[cur].second]--;
            for (auto& v : e[u]) {
                int x = v.first, y = v.second;
                d[y] = d[u] + x;
                Dfs(y);
                res[u] += res[y] + 1;
            }
            path.pop_back();
        };
        Dfs(1);
        for (i = 1; i <= n; ++i) {
            cout << res[i] << " \n"[i == n];
        }
    }
    return 0;
}