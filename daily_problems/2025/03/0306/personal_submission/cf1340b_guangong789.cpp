#include <bits/stdc++.h>
using namespace std;

vector<int> status = {119, 18, 93, 91, 58, 107, 111, 82, 127, 123}; // 合法点亮状态转化成十进制数

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> now(n);
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (int j = 0; j < 7; ++j) {
            now[i] |= (s[j] - '0') << (6 - j); // 将当前状态转化成十进制数
        }
    }
    vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
    dp[n][0] = 1;

    for (int i = n-1; i >= 0; --i) {
        for (int j = 0; j <= k; ++j) {
            if (dp[i+1][j]) { // 遍历后一个用j次可以合法点亮的状态
                for (int sta = 0; sta < 10; ++sta) { // 检查当前这个能够合法点亮的状态有哪些
                    if ((status[sta] & now[i]) == now[i]) {  // 可以点亮
                        int need = __builtin_popcount(status[sta] ^ now[i]);  // 还要点亮几根
                        if (j + need <= k) { // 后面用的次数加当前次数要小于等于k
                            dp[i][j+need] = 1;
                        }
                    }
                }
            }
        }
    }
    if (dp[0][k] == 0) { // 恰好使用k次达成不了
        cout << -1;
    } else {
        int have = k;
        for (int i = 0; i < n; ++i) { // 从高位向低位考虑
            for (int j = 9; j >= 0; --j) { // 从大数字向小数字考虑
                if ((status[j] & now[i]) == now[i]) {
                    int need = __builtin_popcount(status[j] ^ now[i]);
                    if (have - need >= 0 && dp[i+1][have-need]) {
                        have -= need;
                        cout << j;
                        break;
                    }
                }
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}