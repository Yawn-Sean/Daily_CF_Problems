#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int mod = 1e9 + 7;
  int n;
  cin >> n;
  vector dp(n, vector<int>(2, 0));
  dp[0][0] = 1;
  for (int i = 1; i < n; i++) {
    dp[i][0] = dp[i - 1][0];
    dp[i][1] = dp[i - 1][1];
    if (i % 2) {
      dp[i][1] += dp[i - 1][0] + 1;
      dp[i][1] %= mod;
    } else {
      dp[i][0] += dp[i - 1][1] + 1;
      dp[i][0] %= mod;
    }
  }
  cout << (dp[n - 1][0] + dp[n - 1][1]) % mod << '\n';
}
