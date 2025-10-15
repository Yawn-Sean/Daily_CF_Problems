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
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int p;
  cin >> p;
  if (accumulate(a.begin(), a.end(), 0) <= p) {
    cout << n << '\n';
    return 0;
  }
  vector<double> fac(n + 1);
  fac[0] = 1;
  for (int i = 1; i < n + 1; i++) {
    fac[i] = fac[i - 1] * i;
  }
  debug(fac);
  vector dp(n + 1, vector(n + 1, vector(p + 1, 0.0)));
  double res{};
  for (int x = 1; x <= n; x++) {
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= i; j++) {
        for (int k = 0; k <= p; k++) {
          dp[i][j][k] = dp[i - 1][j][k];
          if (i == x) {
            continue;
          }
          if (j - 1 >= 0 && k - a[i - 1] >= 0) {
            dp[i][j][k] += dp[i - 1][j - 1][k - a[i - 1]];
          }
        }
      }
    }
    for (int j = 1; j < n; j++) {
      for (int k = 0; k <= p; k++) {
        if (k + a[x - 1] > p) {
          res += dp[n][j][k] * fac[j] * fac[n - j - 1] * j;
        }
      }
    }
    debug(res);
  }
  cout << res / fac[n] << '\n';
}
