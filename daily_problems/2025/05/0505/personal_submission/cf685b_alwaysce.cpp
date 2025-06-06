#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 inf = 1e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    
    int n, q;
    cin >> n >> q;

    vector<int> fa(n + 1);
    vector<vector<int>> path(n + 1);
    for (int i = 2; i <= n; i++) {
        cin >> fa[i];
        path[fa[i]].push_back(i);
    }

    vector<int> siz(n + 1);
    vector<int> weight(n + 1, 0);
    vector<int> ans(n + 1);

    function<void(int)> dfs = [&](int u) {
        siz[u] = 1;
        ans[u] = u;
        for (auto&v: path[u]) {
            dfs(v);
            siz[u] += siz[v];
            // 向下子树的最大大小
            weight[u] = max(weight[u], siz[v]);
        }

        for (auto&v: path[u]) {
            int p = ans[v];
            while (p != u) {
                if (max(weight[p], siz[u] - siz[p]) <= siz[u] / 2) {
                    ans[u] = p;
                    break;
                } else {
                    p = fa[p];
                }
            }
        }
    };

    dfs(1);
    while (q--) {
        int u;
        cin >> u;
        cout << ans[u] << endl;
    }

    return 0;
}
