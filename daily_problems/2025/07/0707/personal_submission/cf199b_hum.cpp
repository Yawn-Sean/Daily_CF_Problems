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
  array<int, 4> p1{}, p2{};
  cin >> p1[0] >> p1[1] >> p1[2] >> p1[3];
  cin >> p2[0] >> p2[1] >> p2[2] >> p2[3];
  int ans = 0;
  double d = sqrt((p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]));
  function<int(int, int, int)> check = [&](int r, int r1, int r2) {
    if ((d <= r1 - r) || (d <= r - r2) || (d >= r + r2)) {
      return 1;
    }
    return 0;
  };
  int res{};
  res += check(p1[2], p2[2], p2[3]);
  res += check(p1[3], p2[2], p2[3]);
  res += check(p2[2], p1[2], p1[3]);
  res += check(p2[3], p1[2], p1[3]);

  cout << res;
}
