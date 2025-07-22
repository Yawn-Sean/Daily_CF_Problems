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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x: a) {
      cin >> x;
    }
    vector res(n, n);
    for (int z = 0; z < 2; ++z) {
      vector<long long> s(n + 1);
      for (int i = 0; i < n; ++i) {
        s[i + 1] = s[i] + a[i];
      }
      vector p(n, -1);
      for (int i = 1; i < n; ++i) {
        int j = (z ? n - i - 1 : i);
        int l = 1, r = i;
        while (l <= r) {
          int m = (l + r) / 2;
          if (s[i] - s[i - m] > a[i] && p[i - 1] >= i - m) {
            res[j] = min(res[j], m);
            r = m - 1;
          } else {
            l = m + 1;
          }
        }
        if (a[i - 1] > a[i]) res[j] = 1;
        p[i] = a[i] == a[i - 1] ? p[i - 1] : i - 1;
      }
      ranges::reverse(a);
    }
    for (int i = 0; i < n; ++i)
      cout << (res[i] == n ? -1 : res[i]) << ' ';
    cout << '\n';
  }
}
