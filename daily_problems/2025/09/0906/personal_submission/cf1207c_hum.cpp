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

  int t;
  cin >> t;
  long long inf = 1e18;
  while (t--) {
    int n, a, b;
    string s;
    cin >> n >> a >> b >> s;
    long long dp0 = b, dp1 = inf;
    for (auto &c: s) {
      if (c == '1') {
        dp0 = inf, dp1 = dp1 + a + 2 * b;
      } else {
        long long ndp0 = min(dp0 + a + b, dp1 + 2 * a + b);
        long long ndp1 = min(dp1 + a + 2 * b, dp0 + 2 * a + 2 * b);
        dp0 = ndp0, dp1 = ndp1;
      }
    }

    cout << dp0 << '\n';
  }
}
