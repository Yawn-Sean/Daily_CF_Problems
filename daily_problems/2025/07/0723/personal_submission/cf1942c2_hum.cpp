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
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(x);
    for (int i = 0; i < x; i++) {
      cin >> a[i];
    }
    ranges::sort(a);
    vector<int> d(x);
    for (int i = 0; i < x - 1; i++) {
      d[i] = a[i + 1] - a[i];
    }
    d[x - 1] = a[0] + n - a[x - 1];
    vector<int> t0, t1;
    for (int i = 0; i < x; i++) {
      if (d[i] % 2 == 0) {
        t0.push_back(d[i]);
      } else {
        t1.push_back(d[i]);
      }
    }
    debug(t0, t1);
    ranges::sort(t0);
    ranges::sort(t1);
    int res = x - 2;
    for (int v: t0) {
      if (v == 2) {
        res++;
      } else {
        if (y >= v / 2 - 1) {
          y -= v / 2 - 1;
          res += v - 1;
        } else {
          res += y * 2;
          y = 0;
        }
      }
    }
    for (int v: t1) {
      debug(res);
      if (y >= v / 2) {
        y -= v / 2;
        res += v - 1;
      } else {
        res += y * 2;
        y = 0;
      }
    }
    cout << res << '\n';
  }
}
