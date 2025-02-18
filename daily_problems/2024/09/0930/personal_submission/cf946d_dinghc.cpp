#include <bits/stdc++.h>

using namespace std;
constexpr int N = 500;
constexpr int INF = 0x3F3F3F3F;
char s[N + 1];

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    vector<vector<int>> a(n, vector<int>());
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        for (int j = 0, pre = -1; j < m; j++) {
            if (s[j] == '1') {
                if (pre == -1) {
                    a[i].push_back(0);
                } else {
                    a[i].push_back(a[i].back() + j - pre);
                }
                pre = j;
            }
        }
    }
    vector<vector<int>> mn(n, vector<int>(m + 1, INF));
    for (int i = 0; i < n; i++) {
        mn[i][0] = 0;
        if (!a[i].empty()) {
            mn[i][1] = 1;
            for (int j = 1; j < a[i].size(); j++) {
                for (int p = 0; p < j; p++) {
                    mn[i][j - p + 1] = min(mn[i][j - p + 1], a[i][j] - a[i][p] + 1);
                }
            }
        }
    }
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        int mx = a[i - 1].size();
        for (int j = 0; j <= k; j++) {
            for (int p = 0; p <= min(j, mx); p++) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - p] + mn[i - 1][mx - p]);
            }
        }
    }
    int ans = INF;
    for (int i = 0; i <= k; i++) {
        ans = min(ans, dp[n][i]);
    }
    printf("%d\n", ans);
    return 0;
}

