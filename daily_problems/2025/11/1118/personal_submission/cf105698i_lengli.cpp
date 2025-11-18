#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    sort(nums.begin(), nums.end());

    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<vector<int>> dp_acc(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        int pos = 0;
        for (int j = i + 1; j < n; j++) {
            while (pos < i && nums[i] + nums[pos] <= nums[j]) {
                pos++;
            }

            if (pos > 0) {
                dp[i][j] = dp_acc[pos - 1][i];
            }
            dp[i][j] = (dp[i][j] + 1) % MOD;

            if (i > 0) dp_acc[i][j] = dp_acc[i - 1][j];
            dp_acc[i][j] = (dp_acc[i][j] + dp[i][j]) % MOD;
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans = (ans + dp[i][j]) % MOD;
        }
    }

    cout << (ans + n) % MOD << "\n";
    return 0;
}
