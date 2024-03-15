#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

int main() {
    int n;
    cin >> n;

    vector<int64> diff(n - 1);
    int64 pre;
    cin >> pre;
    for (int i = 0; i < n - 1; i++) {
        int64 cur;
        cin >> cur;
        diff[i] = abs(cur - pre);
        pre = cur;
    }

    vector<vector<int64>> dp(n - 1, vector<int64>(2, 0LL));
    dp[0][0] = diff[0];
    for (int i = 1; i < n - 1; i++) {
        dp[i][0] = max(dp[i - 1][1] + diff[i], diff[i]);
        dp[i][1] = dp[i - 1][0] - diff[i];
    }

    int64 ans = LLONG_MIN;
    for (auto& d : dp) {
        ans = max(ans, d[0]);
        ans = max(ans, d[1]);
    }

    cout << ans << "\n";
    return 0;
}
