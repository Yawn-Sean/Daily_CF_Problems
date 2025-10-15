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

  vector<int> xs(3), ys(3);
  for (int i = 0; i < 3; i++)
    cin >> xs[i] >> ys[i];

  if ((xs[0] == xs[1] && xs[1] == xs[2]) || (ys[0] == ys[1] && ys[1] == ys[2])) {
    cout << 1;
  } else {
    for (int i = 0; i < 3; i++) {
      int i1 = (i + 1) % 3, i2 = (i + 2) % 3;
      if (xs[i1] == xs[i2] && (ys[i] <= min(ys[i1], ys[i2]) || ys[i] >= max(ys[i1], ys[i2]))) {
        return cout << 2, 0;
      }
      if (ys[i1] == ys[i2] && (xs[i] <= min(xs[i1], xs[i2]) || xs[i] >= max(xs[i1], xs[i2])))
        return cout << 2, 0;
    }
    cout << 3;
  }
}
