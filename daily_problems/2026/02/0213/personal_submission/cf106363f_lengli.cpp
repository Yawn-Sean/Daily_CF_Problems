#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long MOD = 1e9 + 7;

inline int get_idx(int i, int j, int n) {
    return i * (n + 1) + j;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    int size = (n + 1) * (n + 1);
    vector<vector<long long>> dp(4, vector<long long>(size, 0));
    vector<vector<long long>> ndp(4, vector<long long>(size, 0));

    for (int i = 0; i < n; i++) {
        dp[1][get_idx(i, 0, n)] = 1;
    }

    for (int i = 0; i < n - 1; i++) {
        int max_z = max(i - 2, 0);
        
        for (int x = 1; x <= 3; x++) {
            for (int y = 0; y < n - i; y++) {
                for (int z = 0; z <= max_z; z++) {
                    int cur_idx = get_idx(y, z, n);
                    long long val = dp[x][cur_idx];
                    if (val == 0) continue;

                    // 转移到 ndp[1]
                    ndp[1][get_idx(0, z, n)] = (ndp[1][get_idx(0, z, n)] + val) % MOD;
                    ndp[1][cur_idx] = (ndp[1][cur_idx] - val + MOD) % MOD;

                    if (x < 3) {
                        ndp[x + 1][cur_idx] = (ndp[x + 1][cur_idx] + val) % MOD;
                        ndp[x + 1][get_idx(n - 1 - i, z, n)] = (ndp[x + 1][get_idx(n - 1 - i, z, n)] - val + MOD) % MOD;
                    } else {
                        ndp[3][get_idx(y, z + 1, n)] = (ndp[3][get_idx(y, z + 1, n)] + val) % MOD;
                        ndp[3][get_idx(n - 1 - i, z + 1, n)] = (ndp[3][get_idx(n - 1 - i, z + 1, n)] - val + MOD) % MOD;
                    }
                }
            }
        }

    
        int next_i = i + 1;
        int next_max_z = max(next_i - 2, 0);
        
        for (int x = 1; x <= 3; x++) {
            for (int y = 0; y < n - next_i; y++) {
                for (int z = 0; z <= next_max_z; z++) {
                    int cur_idx = get_idx(y, z, n);
                    int next_y_idx = get_idx(y + 1, z, n);
                    
                    ndp[x][next_y_idx] = (ndp[x][next_y_idx] + ndp[x][cur_idx]) % MOD;
                    dp[x][cur_idx] = ndp[x][cur_idx];
                    ndp[x][cur_idx] = 0;
                }
            }
        }
    }

    long long ans = 0;
    for (int x = 0; x < 4; x++) {
        ans = (ans + dp[x][get_idx(0, k, n)]) % MOD;
    }

    cout << ans << endl;

    return 0;
}
