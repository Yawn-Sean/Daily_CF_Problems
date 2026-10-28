#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
namespace rgs = ranges;

constexpr int md = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> f(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> f[i];
        f[i] = " " + f[i];
    }

    vector<vector<i64>> dp(n + 1, vector<i64>(m + 1)), d(n + 1, vector<i64>(m + 1));
    dp[0][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (f[i][j] == '#') {
                continue;
            }
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % md;
            d[i][j] = (d[i - 1][j] + d[i][j - 1]) % md;
            if (i > 1 && j > 1 && f[i - 1][j] == '.' && f[i][j - 1] == '.' && f[i - 1][j - 1] == '.') {
                d[i][j] = (d[i][j] + dp[i - 1][j - 1] - d[i - 1][j - 1] + md) % md;
            }
        }
    }

    cout << (dp[n][m] - d[n][m] + md) % md << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}