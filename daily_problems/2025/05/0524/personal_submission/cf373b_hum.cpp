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

  long long w, m, k;
  cin >> w >> m >> k;
  w /= k;
  long long lim{10}, cnt{1};
  long long res{};
  while (true) {
    if (lim < m) {
      lim *= 10;
      cnt++;
      continue;
    }
    long long cur = lim - m;
    if (cur * cnt <= w) {
      w -= cur * cnt;
      res += cur;
      m = lim;
      lim *= 10;
      cnt++;
    } else {
      res += w / cnt;
      break;
    }
  }
  cout << res;
}
