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

  int n;
  cin >> n;
  vector<array<int, 2>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i][0] >> a[i][1];
  }
  ranges::sort(a);
  long long inf = 1e18;
  vector dp(n, vector(n, inf));
  dp[0][0] = a[0][1];
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      dp[i][j] = dp[i - 1][j] + a[i][0] - a[j][0];
      dp[i][i] = min(dp[i][i], dp[i - 1][j]);
    }
    dp[i][i] += a[i][1];
  }
  long long res = inf;
  for (int i = 0; i < n; i++) {
    res = min(res, dp[n - 1][i]);
  }
  cout << res << '\n';
}
