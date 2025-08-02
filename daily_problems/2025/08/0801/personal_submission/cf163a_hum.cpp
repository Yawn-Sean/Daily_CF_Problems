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

  string s, t;
  cin >> s >> t;
  int n1 = s.size(), n2 = t.size();
  vector dp(n1 + 1, vector<int>(n2 + 1));
  int mod = 1e9 + 7;
  for (int i = 1; i <= n1; i++) {
    for (int j = 1; j <= n2; j++) {
      dp[i][j] = dp[i][j - 1];
      if (s[i - 1] == t[j - 1]) {
        dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] + 1) % mod;
      }
    }
  }
  int res{};
  for (int i = 1; i <= n1; i++) {
    res = (res + dp[i][n2]) % mod;
  }
  cout << res << '\n';
}
