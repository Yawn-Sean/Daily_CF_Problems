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

  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> idx(n);
  ranges::iota(idx, 0);
  ranges::sort(idx, [&](int i, int j) {
    return a[i] < a[j];
  });
  int l = 1, r = n;
  while (l < r) {
    int m = l + r >> 1;
    bool f = true;
    for (int i = m; i < n; i++) {
      if (a[idx[i]] - a[idx[i - m]] <= k) {
        f = false;
        break;
      }
    }
    if (f) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  cout << l << '\n';
  vector<int> res(n);

  for (int i = 0; i < n; i++) {
    res[idx[i]] = i % l + 1;
  }
  for (int i = 0; i < n; i++) {
    cout << res[i] << " \n"[i == n - 1];
  }
}
