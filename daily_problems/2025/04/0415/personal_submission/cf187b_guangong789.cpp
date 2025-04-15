#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e9+5;
const int MOD = 1e9+7;
const int inf = 0x3f3f3f3f;

int dis[60][60][60];

void solve() {
    int n, m, r;
    cin >> n >> m >> r;
    memset(dis, 0x3f, sizeof dis);
    while (m--) {
        vector<vector<int>> g(n, vector<int>(n, inf));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> g[i][j];
            }
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }
        // 一步从 i 到 j 的最短路径
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dis[0][i][j] = min(dis[0][i][j], g[i][j]);
            }
        }
    }
    // 先用 change-1 步从 i 走到 k，再从 k 一步走到 j
    for (int change = 1; change < n; ++change) {
        for (int i = 0; i < n; ++i) {
            for (int k = 0; k < n; ++k) {
                for (int j = 0; j < n; ++j) {
                    dis[change][i][j] = min(dis[change][i][j], dis[change-1][i][k] + dis[0][k][j]);
                }
            }
        }
    }
    while (r--) {
        int start, end, changes;
        cin >> start >> end >> changes;
        start--, end--;
        changes = min(n-1, changes);
        cout << dis[changes][start][end] << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T = 1;
//    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
