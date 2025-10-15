#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> paths(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        --u; --v;
        int w = (c - 'a');
        paths[u].emplace_back(v, w);
    }

    vector<vector<vector<int>>> memo(26, vector<vector<int>>(n, vector<int>(n, -1)));

    function<void(int,int,int)> dfs = [&](int u, int v, int c) {
        if (memo[c][u][v] != -1) {
            return;
        }
        memo[c][u][v] = 0;
        for (auto& [nu, w]: paths[u]) {
            if (w >= c) {
                dfs(v, nu, w);
                if (memo[w][v][nu] == 0) {
                    memo[c][u][v] = 1;
                }
            }
        }
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (memo[0][i][j] == -1) {
                dfs(i, j, 0);
            }
            cout << (memo[0][i][j] == 1 ? 'A' : 'B');
        }
        cout << '\n';
    }


    return 0;
}
