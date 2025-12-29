#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int mod = 1000000007;

    int n, x, y;
    cin >> n >> x >> y;

    x = n - x;
    y = n - y;

    vector<vector<int>> dp(x + 1, vector<int>(x + 1, 0));

    int rev2 = (mod + 1) / 2;

    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < i; j++) {
            long long v = dp[i - 1][abs(j - 1)];
            if (j + 1 <= i - 1) {
                v += dp[i - 1][j + 1];
            }
            dp[i][j] = (v * rev2 + 1) % mod;
        }
    }

    cout << dp[x][y] << '\n';
    return 0;
}
