#include <bits/stdc++.h>

using namespace std;
using int64 = long long;
constexpr int N = 1000;
int64 dp[N + 1][N + 1];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, q;
        scanf("%d%d", &n, &q);
        for (int i = 0; i <= N; i++) memset(dp[i], 0, sizeof(dp[i]));
        for (int i = 0, h, w; i < n; i++) {
            scanf("%d%d", &h, &w);
            dp[h][w] += h * w;
        }
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                dp[i][j] += dp[i - 1][j];
                dp[i][j] += dp[i][j - 1];
                dp[i][j] -= dp[i - 1][j - 1];
            }
        }
        for (int i = 0, h1, w1, h2, w2; i < q; i++) {
            scanf("%d%d%d%d", &h1, &w1, &h2, &w2);
            printf("%lld\n", dp[h2 - 1][w2 - 1] - dp[h2 - 1][w1] - dp[h1][w2 - 1] + dp[h1][w1]);
        }
    }
    return 0;
}

