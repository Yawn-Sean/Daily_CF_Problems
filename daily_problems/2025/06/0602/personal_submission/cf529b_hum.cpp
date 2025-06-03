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
  vector<int> w(n), h(n);
  int m{};
  for (int i = 0; i < n; ++i) {
    cin >> w[i] >> h[i];
    m = max(m, max(w[i], h[i]));
  }
  int res = 1e9;
  for (int j = 1; j <= m; ++j) {
    int s{}, cnt{};
    vector<int> t;
    bool b = true;
    for (int i = 0; i < n; ++i) {
      if (h[i] > j && w[i] > j) {
        b = false;
      }
      if (h[i] > j) {
        s += h[i];
        cnt++;
      } else {
        s += w[i];
        if (w[i] <= j) {
          t.push_back(h[i] - w[i]);
        }
      }
    }
    if (!b || cnt > n / 2) {
      continue;
    }
    ranges::sort(t);
    for (int i = 0; i < n / 2 - cnt && i < t.size() && t[i] < 0; ++i) {
      s += t[i];
    }
    res = min(res, j * s);
  }
  cout << res;
}
