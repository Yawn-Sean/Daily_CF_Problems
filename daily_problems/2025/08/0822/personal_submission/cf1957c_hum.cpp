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
  while (t--) {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
      int x, y;
      cin >> x >> y;
      if (x == y) {
        n -= 1;
      } else {
        n -= 2;
      }
    }
    if (n <= 1) {
      cout << 1 << endl;
      continue;
    }
    vector<long long> f(n + 1);
    f[0] = 1;
    f[1] = 1;
    int mod = 1e9 + 7;
    for (int i = 2; i <= n; i++) {
      f[i] = f[i - 1] + (2 * i - 2) * f[i - 2] % mod;
      f[i] %= mod;
    }
    cout << f[n] << endl;
  }
}
