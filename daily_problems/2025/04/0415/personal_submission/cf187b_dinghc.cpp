#include <bits/stdc++.h>
 
using namespace std;
constexpr int INF = 1e9;
constexpr int A = 60;
int dp[A][A][A];
int ans[A][A][A];

int main() {
    int n, m, r;
    scanf("%d%d%d", &n, &m, &r);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                scanf("%d", &dp[i][j][k]);
            }
        }
    }
    for (int t = 0; t < m; t++) {
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dp[t][i][j] = min(dp[t][i][j], dp[t][i][k] + dp[t][k][j]);
                }
            }
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans[k][i][j] = INF;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int t = 0; t < m; t++) {
                ans[0][i][j] = min(ans[0][i][j], dp[t][i][j]);
            }
        }
    }
    for (int k = 1; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int p = 0; p < n; p++) {
                    ans[k][i][j] = min(ans[k][i][j], ans[k - 1][i][p] + ans[0][p][j]);
                }
            }
        }
    }
    for (int i = 0, u, v, k; i < r; i++) {
        scanf("%d%d%d", &u, &v, &k);
        u -= 1;
        v -= 1;
        int res = INF;
        for (int p = 0; p <= min(k, n - 1); p++) {
            res = min(res, ans[p][u][v]);
        }
        printf("%d\n", res);
    }
    return 0;
}

