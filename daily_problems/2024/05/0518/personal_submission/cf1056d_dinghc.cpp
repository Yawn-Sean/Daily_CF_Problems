#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> g(n, vector<int>());
    for (int i = 1, p; i <= n - 1; i++) {
        cin >> p;
        g[i].push_back(p - 1);
        g[p - 1].push_back(i);
    }
    vector<int> colors(n, 0);
    int leaves = 0;
    function<int(int, int)> dfs = [&] (int u, int pa) -> int {
        if (g[u].size() == 1 && g[u][0] == pa) {
            leaves++;
            colors[1] += 1;
            return 1;
        }
        int res = 0;
        for (auto& v : g[u]) {
            if (v != pa) {
                res += dfs(v, u);
            }
        }
        colors[res] += 1;
        return res;
    };
    dfs(0, -1);
    for (int i = 1; i <= leaves; i++) {
        colors[i] += colors[i - 1];
    }
    for (int k = 1, i = 1; k <= n; k++) {
        if (colors[i] >= k) {
            cout << i << " ";
        } else {
            while (colors[i] < k) {
                i++;
            }
            cout << i << " ";
        }
    }
    cout << "\n";
    return 0;
}

