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

  int n, m, q;
  cin >> n >> m >> q;
  vector<long long> a(n), b(m);
  long long suma{}, sumb{};
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    suma += a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
    sumb += b[i];
  }
  set<long long> sa, sb;
  for (int i = 0; i < n; i++) {
    sa.insert(suma - a[i]);
  }
  for (int i = 0; i < m; i++) {
    sb.insert(sumb - b[i]);
  }
  while (q--) {
    int x;
    cin >> x;
    bool f{};
    int cur = abs(x);
    for (int i = 1; i * i <= cur; i++) {
      if (cur % i == 0) {
        if (sa.contains(i) && sb.contains(x / i)) {
          f = true;
          break;
        }
        if (sa.contains(-i) && sb.contains(-x / i)) {
          f = true;
          break;
        }
        if (sb.contains(i) && sa.contains(x / i)) {
          f = true;
          break;
        }
        if (sb.contains(-i) && sa.contains(-x / i)) {
          f = true;
          break;
        }
      }
    }
    cout << (f ? "YES\n" : "NO\n");
  }
}
