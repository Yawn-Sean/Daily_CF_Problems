#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    vector<vector<int>> dp1(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp1[i][j] = a[i - 1][j - 1] + max(dp1[i - 1][j], dp1[i][j - 1]);
        }
    }
    vector<vector<int>> dp2(n + 1, vector<int>(m + 1, 0));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            dp2[i][j] = a[i][j] + max(dp2[i + 1][j], dp2[i][j + 1]);
        }
    }
    vector<vector<int>> dp3(n + 1, vector<int>(m + 1, 0));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 1; j <= m; j++) {
            dp3[i][j] = a[i][j - 1] + max(dp3[i + 1][j], dp3[i][j - 1]);
        }
    }
    vector<vector<int>> dp4(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = m - 1; j >= 0; j--) {
            dp4[i][j] = a[i - 1][j] + max(dp4[i - 1][j], dp4[i][j + 1]);
        }
    }
    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            ans = max(ans, dp1[i][j + 1] + dp2[i + 1][j] + dp3[i][j] + dp4[i + 1][j + 1]);
            ans = max(ans, dp1[i + 1][j] + dp2[i][j + 1] + dp3[i + 1][j + 1] + dp4[i][j]);
        }
    }
    printf("%d\n", ans);
    return 0;
}

