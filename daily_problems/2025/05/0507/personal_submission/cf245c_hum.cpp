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
  vector<int> a(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i + 1];
  }
  if (n <= 2 || n % 2 == 0) {
    cout << -1;
    return 0;
  }
  int res{};
  for (int i = n; i >= 1; --i) {
    if (a[i] > 0) {
      if (i % 2) {
        res += a[i];
        a[i - 1] -= a[i];
        a[i / 2] -= a[i];
      } else {
        res += a[i];
        a[i / 2] -= a[i];
      }
    }
  }
  cout << res << endl;
}
