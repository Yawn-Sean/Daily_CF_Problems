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
  vector<array<int, 3>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i][0] >> a[i][1] >> a[i][2];
  }
  double res = 1e12;
  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      double d1 = sqrt(
        (a[0][0] - a[i][0]) * (a[0][0] - a[i][0]) + (a[0][1] - a[i][1]) * (a[0][1] - a[i][1]) + (a[0][2] - a[i][2]) * (
          a[0][2] - a[i][2]));
      double d2 = sqrt(
        (a[0][0] - a[j][0]) * (a[0][0] - a[j][0]) + (a[0][1] - a[j][1]) * (a[0][1] - a[j][1]) + (a[0][2] - a[j][2]) * (
          a[0][2] - a[j][2]));
      double d3 = sqrt(
        (a[i][0] - a[j][0]) * (a[i][0] - a[j][0]) + (a[i][1] - a[j][1]) * (a[i][1] - a[j][1]) + (a[i][2] - a[j][2]) * (
          a[i][2] - a[j][2])
      );
      res = min(res, (d1 + d2 + d3) / 2);
    }
  }
  cout << fixed << setprecision(10) << res << '\n';
}
