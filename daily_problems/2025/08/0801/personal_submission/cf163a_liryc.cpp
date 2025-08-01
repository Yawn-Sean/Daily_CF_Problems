/** 
https://codeforces.com/problemset/submission/163/331877662
DP
*/
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int MOD = 1000000007;
int dp[5001][5001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    memset(dp, 0, sizeof(dp));
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        dp[i][0] = 1;
        for (int j = 0; j < m; ++j) {
            dp[i][j + 1] += dp[i][j];
            if (dp[i][j + 1] >= MOD)
                dp[i][j + 1] -= MOD;
            if (s[i] == t[j]) {
                dp[i + 1][j + 1] += dp[i][j];
                if (dp[i + 1][j + 1] >= MOD)
                    dp[i + 1][j + 1] -= MOD;

                ans += dp[i][j];
                if (ans >= MOD)
                    ans -= MOD;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
