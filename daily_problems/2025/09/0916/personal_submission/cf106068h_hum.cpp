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
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<int> cubes(1000);
  for (int i = 0; i < 1000; i++) {
    cubes[i] = i * i * i;
  }
  int q;
  cin >> q;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int idx, v;
      cin >> idx >> v;
      a[idx - 1] = v;
    } else {
      int idx;
      cin >> idx;
      if (n - idx >= 1000) cout << n << '\n';
      else if (idx - 1 >= 1000) cout << 1 << '\n';
      else {
        idx--;
        int ans = -2;
        for (int i = 0; i < n; i++) {
          if (cubes[abs(i - idx)] >= a[i]) {
            ans = i;
            break;
          }
        }
        cout << ans + 1 << '\n';
      }
    }
  }
}
