#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<set<int>> g(n, set<int>());
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        g[x].insert(y);
        g[y].insert(x);
    }

    vector<int> ans;
    vector<bool> vis(n, false);
    function<void(int)> dfs = [&] (int u) {
        ans.push_back(u);
        vis[u] = true;
        for (auto& v : g[u]) {
            if (!vis[v]) {
                dfs(v);
                break;
            }
        }
    };
    
    dfs(0);
    int r = ans.size();
    int i = 0;
    for (; i < r; i++) {
        if (g[ans[r - 1]].count(ans[i])) break;
    }
    cout << r - i << "\n";
    for (int j = i; j < r; j++) {
        cout << ans[j] + 1 << " ";
    }
    cout << "\n";

    return 0;
}
