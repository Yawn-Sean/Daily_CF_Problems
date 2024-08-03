#include <iostream>
#include <vector>
using namespace std;
#define int long long

int mod = 1e9 + 7;

void yrlpSolve() {
    int n, k; cin >> n >> k;
    vector<vector<int>> dp(k + 10, vector<int>(n + 10, 1));
    for (int i = 2; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i][j - 1] + dp[i - 1][n - j];
            dp[i][j] %= mod;
        }
    }
    cout << dp[k][n] << endl;
    return; 
}

signed main() {
    int T = 1; cin >> T;
    while (T--) yrlpSolve();
}
