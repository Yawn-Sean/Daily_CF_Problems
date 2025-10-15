#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void solve() {
  int q;
  cin >> q;

  long long l = -1, r = 1e18;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int a, b, n;
      cin >> a >> b >> n;
      long long nl{}, nr{};
      if (n == 1) {
        nl = 1, nr = a;
      } else {
        nl = 1ll * (a - b) * (n - 2) + a + 1, nr = 1ll * (a - b) * (n - 1) + a;
      }
      if (nl > r || nr < l) {
        cout << "0 ";
      } else {
        cout << "1 ";
        l = max(l, nl);
        r = min(r, nr);
      }
    } else {
      int a, b;
      cin >> a >> b;
      long long res1 = max(1ll, 1ll * (l - b - 1) / (a - b) + 1);
      long long res2 = max(1ll, 1ll * (r - b - 1) / (a - b) + 1);
      if (res1 == res2) {
        cout << res1 << " ";
      } else {
        cout << -1 << " ";
      }
    }
  }
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    solve();
    cout<< "\n";
  }
}
