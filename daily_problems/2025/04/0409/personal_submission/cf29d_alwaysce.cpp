#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    /*
        
    */
    int n;
    cin >> n;
    vector<vector<int>> path(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        path[u].push_back(v);
        path[v].push_back(u);
    }

    int k = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0 && path[i].size() == 1) {
            k++;
        }
    }

    vector<int> nodes(k), vis(n, n);
    for (int i = 0; i < k; i++) {
        cin >> nodes[i];
        nodes[i]--;
        vis[nodes[i]] = i;
    }

    function<void(int,int)> dp = [&](int u, int p) {
        for (auto&v: path[u]) {
            if (v == p) continue;
            dp(v, u);
            vis[u] = min(vis[u], vis[v]);
        }
    };

    dp(0, -1);
    vector<int> ans;
    function<void(int,int)> dfs = [&](int u, int p) {
        sort(path[u].begin(), path[u].end(), [&](int i, int j) {
            return vis[i] < vis[j];
        });

        for (auto&v: path[u]) {
            if (v != p) {
                ans.emplace_back(u);
                dfs(v, u);
            }
        }
        ans.emplace_back(u);
    };

    dfs(0, -1);
    int idx = 0;
    for (auto&x: ans) {
        if (idx < k && nodes[idx] == x) {
            idx++;
        }
    }
    if (idx == k) {
        for (auto&x: ans) {
            cout << x + 1 << ' ';
        }
    } else {
        cout << -1 << endl;
    }
    return 0;
}
