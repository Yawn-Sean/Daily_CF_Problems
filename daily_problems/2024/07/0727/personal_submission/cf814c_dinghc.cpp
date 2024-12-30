#include <bits/stdc++.h>

using namespace std;
constexpr int N = 1500;
constexpr int A = 26;
char s[N + 1];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    vector<vector<int>> dp(A, vector<int>(n + 1, 0));
    for (int c = 0; c < A; c++) {
        for (int i = 0; i < n; i++) {
            int curr = 0;
            for (int j = i; j < n; j++) {
                if (s[j] == 'a' + c) {
                    curr++;
                }
                dp[c][j - i + 1 - curr] = max(dp[c][j - i + 1 - curr], j - i + 1);
            }
            for (int k = 1; k <= n; k++) {
                dp[c][k] = max(dp[c][k - 1], dp[c][k]);
            }
        }
    }
    int q;
    scanf("%d", &q);
    int m;
    char c;
    for (int i = 0; i < q; i++) {
        scanf("%d %c", &m, &c);
        printf("%d\n", dp[c - 'a'][m]);
    }
    return 0;
}

