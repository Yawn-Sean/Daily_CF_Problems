#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        vector<int> a(n + 1, 0);
        for (int i = 0, x; i < n; i++) {
            scanf("%d", &x);
            if (x < n) a[x] += 1;
        }
        int m = n;
        for (int i = 0; i < n; i++) if (a[i] == 0) {
            m = i;
            break;
        }
        if (m == 0) {
            printf("0\n");
        } else {
            vector<vector<long long>> dp(m, vector<long long>(m + 1, 0LL));
            for (int i = 1; i <= m; i++) {
                dp[0][i] = 1LL * a[0] * i;
            }
            for (int i = 1; i < m; i++) {
                for (int p = 1; p <= m; p++) {
                    dp[i][p] = min(dp[i - 1][p], dp[i - 1][i] + 1LL * a[i] * p);
                }
            }
            printf("%lld\n", dp[m - 1][m] - m);
        }
    }
    return 0;
}

