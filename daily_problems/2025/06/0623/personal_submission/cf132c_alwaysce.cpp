#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9+7;

i64 qpow(i64 a, i64 b, i64 m) {
    i64 res = 1;
    a %= m;
    while (b > 0) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

i64 inv_mod(i64 a, i64 m) {
    return qpow(a, m - 2, m);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    int n;
    cin >> n;
    
    int l = s.size();

    // 前i个字符 修改了j次 长度=l 是否可行
    // 如果可行 dp[i][j][l] = 1
    // 否则 dp[i][j][l] = 0
    // i维度压缩掉
    // 方向 | 修改次数 | 位置
    vector<vector<vector<int>>> dp(2, vector<vector<int>>(n + 1, vector<int>(2 * l + 1, 0)));
    dp[0][0][l] = 1; // 初始状态，0次修改

    vector<vector<vector<int>>> ndp(2, vector<vector<int>>(n + 1, vector<int>(2 * l + 1, 0)));

    for (int i = 1; i <= l; i++) {
        char cur = s[i - 1];
        if (cur == 'F') {
            for (int d = 0; d < 2; d++) {
                for (int pre_op = 0; pre_op <= n; pre_op++) {
                    for (int pre_l = 0; pre_l <= 2 * l; pre_l++) {
                        if (dp[d][pre_op][pre_l] == 0) continue;
                        // 不修改 F
                        int add = (d % 2 == 0) ? 1 : -1; // F -> T 或 T -> F
                        int new_l = pre_l + add;
                        ndp[d][pre_op][new_l] = 1;

                        // 修改成 F
                        if (pre_op + 1 <= n) {
                            int new_l = pre_l; // 不改变长度 方向改变
                            ndp[1 - d][pre_op + 1][new_l] = 1;
                        }
                    }
                }
            }
        } else {
            // cur == 'T'
            for (int d = 0; d < 2; d++) {
                for (int pre_op = 0; pre_op <= n; pre_op++) {
                    for (int pre_l = 0; pre_l <= 2 * l; pre_l++) {
                        if (dp[d][pre_op][pre_l] == 0) continue;
                    
                        // T 不修改
                        ndp[1 - d][pre_op][pre_l] = 1; // 方向改变
                    
                        // T 修改成 F
                        if (pre_op + 1 <= n) {
                            int add = (d % 2 == 0) ? 1 : -1; // T -> F 或 F -> T
                            ndp[d][pre_op + 1][pre_l + add] = 1; // 修改后长度改变
                        }
                    }  
                }
            }
        }
        
        dp = ndp;
        ndp = vector<vector<vector<int>>>(2, vector<vector<int>>(n + 1, vector<int>(2 * l + 1, 0)));
    }

    int ans = 0;
    for (int d = 0; d < 2; d++) {
        for (int num_op = 0; num_op <= n; num_op++) {
            if ((n - num_op) % 2 == 0) {
                for (int j = 0; j <= 2 * l; j++) {
                    if (dp[d][num_op][j] == 1) {
                        ans = max(ans, abs(j - l));
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
