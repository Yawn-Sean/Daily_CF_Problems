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

  function<int(int)> get = [&](int x) {
    int res{};
    while (x) {
      res++;
      x /= 7;
    }
    return max(res, 1);
  };
  int ln = get(n - 1);
  int lm = get(m - 1);

  if (ln + lm > 7) {
    cout << 0 << "\n";
    return 0;
  }

  function<bool(int, int)> check = [&](int x, int y) {
    vector<bool> vis(ln + lm);
    for (int i = 0; i < ln; i++) {
      if (vis[x % 7]) {
        return false;
      }
      vis[x % 7] = true;
      x /= 7;
    }
    for (int i = 0; i < lm; i++) {
      if (vis[y % 7]) {
        return false;
      }
      vis[y % 7] = true;
      y /= 7;
    }
    return true;
  };

  int res{};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (check(i, j)) {
        res++;
      }
    }
  }
  cout << res << endl;
}
