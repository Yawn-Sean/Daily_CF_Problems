#include <bits/stdc++.h>

using namespace std;
using li = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<li> dp(n + 1, 0LL);
    vector<li> dp_pre(n + 1);
    dp[1] = dp_pre[1] = 1LL;
    li diff = 0LL;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp_pre[i - 1];
        diff = (diff + dp[1] - dp[0]) % m;
        for (int p = 2; p * p <= i; p++) {
            if (i % p == 0) {
                diff = (diff + m + dp[i / p] - dp[(i - 1) / p]) % m;
                int q = i / p;
                if (q != p) {
                    diff = (diff + m + dp[i / q] - dp[(i - 1) / q]) % m;
                }
            }
        }
        dp[i] = (dp[i] + diff) % m;
        dp_pre[i] = (dp_pre[i - 1] + dp[i]) % m;
    }
    cout << dp[n] << "\n";
    return 0;
}

