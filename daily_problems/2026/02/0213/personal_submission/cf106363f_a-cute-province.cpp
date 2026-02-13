#include <bits/stdc++.h>
#define cute_prov0nce main
using namespace std;
typedef pair<int, int> PII;
const int mod = 1e9 + 7;


int dp[505][4][505];
int ndp[505][4][505];

void solve() {
    int n, k_target;
    cin >> n >> k_target;

    for (int rk = 0; rk < n; rk++) {
        dp[0][1][rk] = 1;
    }

    for (int i = 1; i < n; i++) {

        memset(ndp, 0, sizeof(ndp));

        for (int x = 0; x <= k_target; x++) {
            for (int y = 1; y <= 3; y++) {
                for (int z = 0; z <= n - i; z++) {
                    if (!dp[x][y][z]) continue;
                    int val = dp[x][y][z];

             
                    if (z > 0) {
                        ndp[x][1][0] = (ndp[x][1][0] + val) % mod;
                        ndp[x][1][z] = (ndp[x][1][z] - val + mod) % mod;
                    }

           
                    if (z <= n - i - 1) {
                        int xx = x + (y == 3 ? 1 : 0);
                        int yy = min(3, y + 1);
                        if (xx <= k_target) {
                            ndp[xx][yy][z] = (ndp[xx][yy][z] + val) % mod;
                            ndp[xx][yy][n - i] = (ndp[xx][yy][n - i] - val + mod) % mod;
                        }
                    }
                }
            }
        }

        for (int x = 0; x <= k_target; x++) {
            for (int y = 1; y <= 3; y++) {
                int cur_sum = 0;
                for (int z = 0; z < n - i; z++) {
                    cur_sum = (cur_sum + ndp[x][y][z]) % mod;
                    dp[x][y][z] = cur_sum;
                }
              
            }
        }
    }

    int ans = 0;
    for (int y = 1; y <= 3; y++) ans = (ans + dp[k_target][y][0]) % mod;
    cout << ans << '\n';
}

int cute_prov0nce() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
