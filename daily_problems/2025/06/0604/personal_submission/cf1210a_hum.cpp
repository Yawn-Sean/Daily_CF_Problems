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
  vector g(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  if (n <= 6) {
    cout << m << '\n';
    return 0;
  }
  int res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int cur = m;
      for (int x: g[i]) {
        for (int y: g[j]) {
          if (x == y) {
            cur--;
          }
        }
      }
      res = max(res, cur);
    }
  }
  cout << res << '\n';
}
