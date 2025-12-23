#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, p;
    cin >> n >> p;

    p = min(p, 20);

    const int INF = 1000000000;
    vector<vector<int>> dp(p + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= n; i++) {
        dp[0][i] = 1;
    }

    for (int i = 1; i <= p; i++) {
        dp[i][0] = 1;
        for (int j = 1; j <= n; j++) {
            long long val = (long long)dp[i - 1][j - 1] + dp[i][j - 1];
            dp[i][j] = (int)min<long long>(val, INF);
        }
    }

    for (int i = 0; i <= n; i++) {
        if (dp[p][i] >= n) {
            cout << i << '\n';
            break;
        }
    }

    return 0;
}
