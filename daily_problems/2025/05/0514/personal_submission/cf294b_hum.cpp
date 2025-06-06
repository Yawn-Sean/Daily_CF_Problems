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
  int inf = 1e8;
  vector dp(n, vector(201, inf));

  dp[0][a[0][0]] = 0;
  dp[0][0] = a[0][1];

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 201; j++) {
      dp[i][j] = min(dp[i][j], dp[i - 1][j] + a[i][1]);
      if (j - a[i][0] >= 0) {
        dp[i][j] = min(dp[i][j], dp[i - 1][j - a[i][0]]);
      }
    }
  }
  for (int i = 0; i < 201; i++) {
    if (i >= dp[n - 1][i]) {
      cout << i << '\n';
      return 0;
    }
  }
}
