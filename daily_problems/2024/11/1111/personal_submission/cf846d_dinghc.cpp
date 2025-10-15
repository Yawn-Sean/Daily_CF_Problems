#include <bits/stdc++.h>

using namespace std;
constexpr int inf = 1'000'000'001;
constexpr int N = 500;
int mat[N + 1][N + 1];
int dp[N + 1][N + 1];

int main() {
    int n, m, k, q;
    scanf("%d%d%d%d", &n, &m, &k, &q);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            mat[i][j] = inf;
        }
    }
    int T = 0;
    for (int i = 0, x, y, t; i < q; i++) {
        scanf("%d%d%d", &x, &y, &t);
        mat[x-1][y-1] = t;
        T = max(t, T);
    }
    int k2 = k * k;
    auto check = [&] (int t) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp[i + 1][j + 1] = mat[i][j] <= t ? 1 : 0;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp[i + 1][j + 1] += dp[i + 1][j] + dp[i][j + 1] - dp[i][j];
            }
        }
        for (int i = 0; i + k <= n; i++) {
            for (int j = 0; j + k <= m; j++) {
                if (dp[i + k][j + k] - dp[i + k][j] - dp[i][j + k] + dp[i][j] == k2) {
                    return true;
                }
            }
        }
        return false;
    };
    int lo = 0, hi = T + 1;
    while (lo <= hi) {
        int mid = (hi + lo) / 2;
        if (check(mid)) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    printf("%d\n", lo > T ? -1 : lo);
    return 0;
}

