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

  int t1, t2, x1, x2, t0;
  cin >> t1 >> t2 >> x1 >> x2 >> t0;

  if (t0 == t1 && t0 == t2) cout << x1 << ' ' << x2;
  else if (t0 == t1) cout << x1 << ' ' << 0;
  else if (t0 == t2) cout << 0 << ' ' << x2;
  else {
    int ans1 = 0, ans2 = x2;

    for (int i = 1; i <= x1; i++) {
      long long t = (1ll * (t0 - t1) * i + t2 - t0 - 1) / (t2 - t0);
      if (t > x2) continue;
      if (1ll * t * ans1 <= 1ll * ans2 * i) ans1 = i, ans2 = t;
    }

    cout << ans1 << ' ' << ans2;
  }
}
