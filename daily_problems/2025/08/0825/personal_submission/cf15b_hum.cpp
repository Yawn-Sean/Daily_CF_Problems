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
    long long n, m, x1, y1, x2, y2;
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;

    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);

    long long a = x1 + n - x2, b = y1 + m - y2;
    cout << n * m - 2 * a * b + max(0ll, 2 * a - n) * max(0ll, 2 * b - m) << '\n';
  }
}
