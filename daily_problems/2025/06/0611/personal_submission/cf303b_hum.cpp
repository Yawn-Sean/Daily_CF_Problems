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

  int n, m, x, y, a, b;
  cin >> n >> m >> x >> y >> a >> b;
  int g = gcd(a, b);
  a /= g;
  b /= g;

  int t = min(n / a, m / b);
  int v = t * a, w = t * b;
  int x0 = min(n - v, max(x - (v + 1) / 2, 0));
  int y0 = min(m - w, max(y - (w + 1) / 2, 0));
  cout << x0 << ' ' << y0 << ' ' << x0 + v << ' ' << y0 + w << "\n";
}
