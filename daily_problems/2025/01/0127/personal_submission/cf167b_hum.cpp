#include <bits/stdc++.h>
using namespace std;


int main() {
  int n, l, k;
  cin >> n >> l >> k;
  vector<array<int, 2>> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i][1];
  }
  for (int i = 0; i < n; ++i) {
    cin >> a[i][0];
  }
  ranges::sort(a, greater{});
  k = min(k, n);
  vector dp(n + 1, vector<double>(n + 1, 0));

  dp[0][k] = 1;


  for (int i = 0; i < n; i++) {
    vector ndp(n + 1, vector<double>(n + 1, 0));
    for (int j = 0; j <= n; j++) {
      for (int v = 0; v <= n; v++) {
        if (dp[j][v]) {
          double p = 0.01 * a[i][1];
          ndp[j][v] += dp[j][v] * (1 - p);
          if (v + a[i][0] >= 0) {
            ndp[j + 1][min(v + a[i][0], n)] += dp[j][v] * p;
          }
        }
      }
    }

    dp = ndp;
  }

  double res = 0;
  for (int i = l; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      res += dp[i][j];
    }
  }
  cout << fixed << setprecision(15) << res << endl;
}
