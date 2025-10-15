#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif


void solve() {
  int a, b, c;
  long long k;
  cin >> a >> b >> c >> k;
  int maa = pow(10, a), mab = pow(10, b), mac = pow(10, c);
  int mia = pow(10, a - 1), mib = pow(10, b - 1), mic = pow(10, c - 1);
  for (int i = mia; i < maa; ++i) {
    long long x = max(mib, mic - i);
    long long y = min(mab, mac - i);
    if (x > y) {
      continue;
    }
    if (y - x >= k) {
      cout << i << " + " << x + k - 1 << " = " << x + k - 1 + i << endl;
      return;
    }
    k -= y - x;
  }
  cout << -1 << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
