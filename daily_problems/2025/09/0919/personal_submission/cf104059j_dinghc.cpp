#include <bits/stdc++.h>

using namespace std;
constexpr int INF = 1e9;
constexpr int N = 1e5;
constexpr int S = 4;
char s[N + 1];
char* p = "hdcs";

int n;

int solve(const string& perm) {
    vector<vector<int>> dp(n + 1, vector<int>(S, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < S; j++) {
            if (s[i] == perm[j]) {
                dp[i + 1][j] = dp[i][j];
                if (j) {
                    dp[i + 1][j] = min(dp[i + 1][j], dp[i][j - 1]);
                }
            } else {
                dp[i + 1][j] = dp[i][j] + 1;
            }
        }
    }
    return dp[n][S - 1];
}

int main() {
    scanf("%s", s);
    n = strlen(s);
    string perm;
    int ans = INF;
    auto dfs = [&] (this auto&& dfs, int msk) {
        if (msk == 0) {
            ans = min(ans, solve(perm));
            return;
        }
        for (int i = 0; i < S; i++) if (msk >> i & 1) {
            perm.push_back(p[i]);
            dfs(msk ^ (1 << i));
            perm.pop_back();
        }
    };
    dfs((1 << S) - 1);
    printf("%d\n", ans);
    return 0;
}

