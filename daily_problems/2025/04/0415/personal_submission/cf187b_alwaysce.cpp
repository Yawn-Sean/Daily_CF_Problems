#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<vector<vector<int>>> dis(60, vector<vector<int>>(60, vector<int>(60, 1e9)));
    int n,m,r;
    cin >> n >> m >> r;
    while (m--) {
        vector<vector<int>> g(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> g[i][j];
            }
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dis[0][i][j] = min(dis[0][i][j], g[i][j]);
            }
        }
        
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                for (int nk = 0; nk < n; nk++) {
                    // 新开一辆车从j->k + k->nk
                    // 其实是<=i次替换
                    dis[i][j][nk] = min(dis[i][j][nk], dis[i - 1][j][k] + dis[0][k][nk]);
                }
            }
        }
    }

    while (r--) {
        int u, v, k;
        cin >> u >> v >> k;
        u--;
        v--;
        cout << dis[min(k, n - 1)][u][v] << '\n';
    }
    /*
        看成线段 i车 从a走到b
        dp[k][i][j]: 从城市i走到城市j 替换次数为k的最小代价
    */

    return 0;
}
