#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    int n, k;
    cin >> n >> k;

    vector<int> seq(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 7; j++) {
            seq[i] |= (s[j] - '0') << (6 - j);
        }
    }

    vector<int> digits = {119, 18, 93, 91, 58, 107, 111, 82, 127, 123};
    // 后缀dp[i][k] [i:n] 操作k次得到的数字 是否合法
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    dp[n][0] = 1;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= k; j++) {
            if (dp[i + 1][j]) {
                for (int digit = 0; digit < 10; digit++) {
                    if ((seq[i] & digits[digit]) == seq[i]) {
                        int nj = j + __builtin_popcount(digits[digit] ^ seq[i]);
                        if (nj <= k) {
                            dp[i][nj] = 1;
                        }
                    }
                }
            }
        }
    }

    if (dp[0][k] != 1) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < n; i++) {
            int ans = 10;
            for (int digit = 9; digit >= 0; digit--) {
                if ((seq[i] & digits[digit]) == seq[i]) {
                    int nk = k - __builtin_popcount(digits[digit] ^ seq[i]);
                    if (nk >= 0 && dp[i + 1][nk]) {
                        ans = digit;
                        k = nk;
                        break;
                    }
                }
            }
            cout << ans;
        }
        cout << endl;
    }

    return 0;
}
