#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<LL, LL> PLL;

/*
中毒至多 O(log n) 次其实就能找到目标饭店
其实可以考虑中毒 i 次，尝试 j 次，能从至多多少个饭店里面找到目标，设为 dp[i][j]
答案是 dp[i][j] >= n 的最小的 j，且 i <= p
*/

void solve() {
    LL n, p;
    cin >> n >> p;
    LL mx = 1e9;
    
    p = min(p, 19LL);
    vector<vector<LL>> dp(p + 1, vector<LL>(n + 1, 1));
    for (int i = 1; i <= p; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
            dp[i][j] = min(dp[i][j], mx);
        }
    }
    
    for (int i = 0; i <= n; i++) {
        if (dp[p][i] >= n) {
            cout << i << "\n";
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
