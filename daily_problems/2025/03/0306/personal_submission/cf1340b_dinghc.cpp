#include <bits/stdc++.h>

using namespace std;
constexpr int A = 7;
constexpr int N = 2000;
int a[N];
int mks[] {0b1110111, 0b0010010, 0b1011101, 0b1011011, 0b0111010, 
            0b1101011, 0b1101111, 0b1010010, 0b1111111, 0b1111011};
char ans[N + 1];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    char s[A + 1];
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        for (int j = A - 1; j >= 0; j--) {
            if (s[j] - '0') a[i] |= 1 << (A - j - 1);
        }
    }
    vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, false));
    dp[n][0] = true;
    for (int i = n - 1; i >= 0; i--) {
        for (auto& mk : mks) {
            if ((a[i] & mk) == a[i]) {
                int m = __builtin_popcount(a[i] ^ mk);
                for (int j = 0; j <= k; j++) {
                    if (dp[i + 1][j] && m + j <= k) dp[i][m + j] = true;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 9; j >= 0; j--) {
            if ((a[i] & mks[j]) == a[i]) {
                int m = __builtin_popcount(a[i] ^ mks[j]);
                if (k >= m && dp[i + 1][k - m]) {
                    k -= m;
                    ans[i] = j + '0';
                    break;
                }
            }
        }
        if (ans[i] == '\0') {
            printf("-1\n");
            return 0;
        }
    }
    printf("%s\n", ans);
    return 0;
}

