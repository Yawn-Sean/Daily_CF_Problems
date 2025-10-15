#include <bits/stdc++.h>

using namespace std;
constexpr int INF = 1e9;
constexpr int N = 100;
constexpr int A = 26;
char s[N + 1];
int bonus[A][A];

int main() {
    int k;
    scanf("%s%d", s, &k);
    int m = strlen(s);
    int n;
    scanf("%d", &n);
    for (int i = 0, b; i < n; i++) {
        char x, y;
        scanf(" %c %c %d", &x, &y, &b);
        bonus[x - 'a'][y - 'a'] = b;
    }
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(k + 1, vector<int>(A, -INF)));
    dp[0][0][s[0] - 'a'] = 0;
    if (k > 0) {
        for (int c = 0; c < A; c++) if (c != s[0] - 'a') {
            dp[0][1][c] = 0;
        }
    }
    for (int i = 0; i < m - 1; i++) {
        int curr = s[i + 1] - 'a';
        for (int j = 0; j <= k; j++) {
            for (int c = 0; c < A; c++) {
                if (j < k) {
                    for (int p = 0; p < A; p++) {
                        dp[i + 1][j + (p != curr)][p] = max(dp[i + 1][j + (p != curr)][p], dp[i][j][c] + bonus[c][p]);
                    }
                }
                dp[i + 1][j][curr] = max(dp[i + 1][j][curr], dp[i][j][c] + bonus[c][curr]);
            }
        }
    }
    int ans = -INF;
    for (int j = 0; j <= k; j++) {
        for (int c = 0; c < A; c++) {
            ans = max(ans, dp[m - 1][j][c]);
        }
    }
    printf("%d\n", ans);
    return 0;
}

