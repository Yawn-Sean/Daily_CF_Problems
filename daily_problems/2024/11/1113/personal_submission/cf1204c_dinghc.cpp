#include <bits/stdc++.h>

using namespace std;
constexpr int N = 100;
char mat[N + 1][N + 1];
constexpr int INF = 0x3f3f3f3f;

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", mat[i]);
    }
    vector<vector<int>> dp(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++) {
        dp[i][i] = 0;
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == '1') {
                dp[i][j] = 1;
            }
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = min(dp[i][k] + dp[k][j], dp[i][j]);
            }
        }
    }
    int m;
    scanf("%d", &m);
    vector<int> path(m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &path[i]);
        path[i] -= 1;
    }
    vector<int> ans{0};
    for (int i = 1; i < m; i++) {
        if (dp[path[ans.back()]][path[i]] != i - ans.back()) {
            ans.push_back(i - 1);
        }
    }
    ans.push_back(m - 1);
    printf("%d\n", ans.size());
    for (auto& v : ans) {
        printf("%d ", path[v] + 1);
    }
    return 0;
}

