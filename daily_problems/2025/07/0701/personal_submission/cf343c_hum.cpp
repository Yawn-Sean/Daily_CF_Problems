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
  vector<long long> a(n), b(m);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];

  function<bool(long long)> check = [&](long long mid) -> bool {
    int j{};
    long long left{};
    for (int i = 0; i < n; i++) {
      if (b[j] <= a[i]) {
        long long last = mid - (a[i] - b[j]);
        if (last < 0) {
          continue;
        }
        left = max(b[j] + last, a[i] + last / 2);
      } else {
        long long last = mid - (b[j] - a[i]);
        if (last < 0) {
          continue;
        }
        left = b[j] + last;
      }
      while (j < m && b[j] <= left) {
        j++;
      }
      if (j == m) {
        return true;
      }
    }
    return false;
  };
  long long l{}, r = 2e10;
  while (l < r) {
    long long mid = (l + r) / 2;
    if (check(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << l << endl;
}
