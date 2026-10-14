#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
namespace rgs = ranges;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edge(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    vector<array<int, 2>> ans;
    auto add = [&](int x, int y) -> void {
        if (x == y) {
            return;
        }
        if (x > y) {
            swap(x, y);
        }
        ans.push_back({x, y});
    };

    for (int i = 1; i <= n; i++) {
        int len = edge[i].size();
        for (int j = 0; j < len; j++) {
            add(i, edge[i][j]);
            for (int k = j + 1; k < len; k++) {
                add(edge[i][j], edge[i][k]);
            }
        }
    }

    rgs::sort(ans);
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    cout << ans.size() << "\n";
    for (const auto& [l, r] : ans) {
        cout << l << " " << r << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}