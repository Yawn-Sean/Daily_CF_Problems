#include <bits/stdc++.h>
 
using namespace std;
constexpr int N = 5000;
char mat[N][N];
int cnt[N + 2];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", mat[i]);
    }
    vector<vector<int>> dp(m + 1, vector<int>(n, 0));
    for (int j = 1; j <= m; j++) {
        for (int i = 0; i < n; i++) {
            dp[j][i] = mat[i][j - 1] == '1' ? dp[j - 1][i] + 1 : 0;
        }
    }
    int ans = 0;
    for (int j = 1; j <= m; j++) {
        memset(cnt, 0, sizeof(cnt));
        for (auto& x : dp[j]) {
            cnt[x] += 1;
        }
        for (int i = m; i >= 1; i--) {
            cnt[i] += cnt[i + 1];
            ans = max(ans, cnt[i] * i);
        }
    }
    printf("%d\n", ans);
    return 0;
}

