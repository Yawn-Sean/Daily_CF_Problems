#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ve vector
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using pi = pair<int, int>;

int inline red() {
    int x;
    cin >> x;
    return x;
}

void solve() {
    const int mod = 998244353;
    int n = red(), k = red();
    ve dp(4, ve<int>(2 * n + 1));
    ve ndp(4, ve<int>(2 * n + 1));
    dp[0][1] = 1, dp[1][2] = 1, dp[2][2] = 1, dp[3][1] = 1;
    ve<ve<int>> grid = {
        {0, 1, 1, 1},
        {0, 0, 2, 0},
        {0, 2, 0, 0},
        {1, 1, 1, 0}
    };
    rep(_, 1, n) {
        rep(msk, 0, 4) {
            rep(j, 0, k + 1) {
                if (dp[msk][j] > 0) {
                    rep(nmsk, 0, 4) {
                        int dj = j + grid[msk][nmsk];
                        ndp[nmsk][dj] = (ndp[nmsk][dj] + dp[msk][j]) % mod;
                    }
                }
            }
        }
        rep(msk, 0, 4) {
            rep(j, 0, k + 1) {
                dp[msk][j] = ndp[msk][j];
                ndp[msk][j] = 0;
            }
        }
    }
    int res = 0;
    rep(msk, 0, 4) {
        res = (res + dp[msk][k]) % mod;
    }

    cout << res << '\n';
}
  
int main() {  
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {  
        solve();
    }  
    return 0;  
}
