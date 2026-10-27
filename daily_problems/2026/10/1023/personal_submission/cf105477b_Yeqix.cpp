#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
namespace rgs = ranges;

constexpr int md = (int)1e9 + 7;
int dp[401][201][201];
int ans[201][201];

void add(int& a, int b) {
    a += b;
    if (a >= md) {
        a -= md;
    }
}

void solve() {
    int l, h;
    cin >> l >> h;
    cout << ans[l][h] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 0; i <= 200; i++) {
        dp[0][0][i] = 1;
    }
    for (int i = 0; i < 400; i++) {
        for (int j = 0; j <= 200; j++) {
            for (int k = j; k <= 200; k++) {
                if (j == k) {
                    if (j > 0) {
                        add(dp[i + 1][j - 1][k], dp[i][j][k]);
                    }
                } else {
                    if (j > 0) {
                        add(dp[i + 1][j - 1][k], dp[i][j][k]);
                    }
                    if (j + 1 <= k) {
                        add(dp[i + 1][j + 1][k], dp[i][j][k]);
                    }
                }
            }
        }
    }

    for (int i = 1; i <= 200; i++) {
        for (int j = 1; j <= 200; j++) {
            add(ans[i][j], dp[i * 2][0][j]);
            add(ans[i][j], md - dp[i * 2][0][j - 1]);
        }
    }

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}