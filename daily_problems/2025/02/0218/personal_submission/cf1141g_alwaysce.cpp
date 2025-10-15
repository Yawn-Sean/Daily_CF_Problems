#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 inf = 1e18;
i64 mod = 1e9+9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    /*
       
    */
    int n, k;
    cin >> n >> k;
    vector<vector<int>> path(n);
    vector<int> deg(n);
    vector<pair<int,int>> edges;

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges.emplace_back(u, v);
        path[u].push_back(i - 1);
        path[v].push_back(i - 1);
        ++deg[u];
        ++deg[v];
    }

    int left = 1, right = n;
    while (left < right) {
        int mid = (left + right) / 2, cnt = 0;
        for (auto&j: deg) {
            if (j > mid) {
                ++cnt;
            }
        }
        if (cnt > k) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    vector<int> ans(n - 1);

    function<void(int,int)> dfs = [&](int u, int c) {
        int cur = 1;
        for (auto& eid: path[u]) {
            if (!ans[eid]) {
                if (path[u].size() > left) {
                    ans[eid] = 1; // 随便染色
                } else {
                    // 如果当前颜色重复了 往后递增
                    if (cur == c) { ++cur; }
                    ans[eid] = cur++;
                }
                int v = edges[eid].first + edges[eid].second - u;
                dfs(v, ans[eid]);
            }
        }
    };

    cout << left << '\n';
    dfs(0, 0);
    for (auto& x: ans) { cout << x << ' '; }
    return 0;
}
