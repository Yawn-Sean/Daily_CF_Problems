#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

int main() {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n - 1; i++) {
        int pi;
        cin >> pi;
        p[i + 1] = pi - 1;
    }

    vector<int> s(n);
    for (auto& si : s) {
        cin >> si;
    }
    
    vector<vector<int>> g(n, vector<int>());
    for (int i = 1; i < n; i++) {
        g[p[i]].push_back(i);
    }

    function<bool(int, int)> dfs1, dfs2;
    int64 ans = 0LL;
    dfs1 = [&] (int u, int sum) -> bool {
        if (s[u] < sum) return false;
        ans += s[u] - sum;
        for (auto& v : g[u]) {
            if (!dfs2(v, s[u])) return false;
        }
        return true;
    };
    
    dfs2 = [&] (int u, int sum) -> bool {
        auto& adj = g[u];        
        if (!adj.empty()) {
            int d = s[adj[0]] - sum;
            if (d < 0) return false;
            for (int i = 1; i < adj.size(); i++) {
                if (s[adj[i]] - sum < 0) return false;
                d = min(d, s[adj[i]] - sum);
            }
            for (auto& v : adj) {
                if (!dfs1(v, sum + d)) return false;
            }
            ans += d;
        }
        return true;
    };

    bool is_exist = dfs1(0, 0);
    if (is_exist) {
        cout << ans << "\n";
    } else {
        cout << "-1\n";
    }

    return 0;
}
