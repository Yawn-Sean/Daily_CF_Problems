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

  int n, m;
  cin >> n >> m;
  vector<array<int, 2>> a(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i][0] >> a[i][1];
  }

  int res = max(a[0][1] + a[0][0] - 1, a[m - 1][1] + n - a[m - 1][0]);

  for (int i = 0; i < m - 1; i++) {
    auto [d1, h1] = a[i];
    auto [d2, h2] = a[i + 1];
    if (abs(h1 - h2) > d2 - d1) {
      cout << "IMPOSSIBLE";
      return 0;
    }
    res = max(res, (h1 + h2 + d2 - d1) / 2);
  }
  cout << res;
}
