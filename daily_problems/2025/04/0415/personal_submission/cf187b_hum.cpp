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
  vector<int> a(n);
  int inf = 1e9;
  vector dis(n, vector(n, vector(n, inf)));
  while (m--) {
    vector g(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> g[i][j];
      }
    }
    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        dis[0][i][j] = min(dis[0][i][j], g[i][j]);
      }
    }
  }

  debug(dis);
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        for (int nk = 0; nk < n; nk++) {
          dis[i][j][nk] = min(dis[i][j][nk], dis[i - 1][j][k] + dis[0][k][nk]);
        }
      }
    }
  }
  while (q--) {
    int x, y, k;
    cin >> x >> y >> k;
    cout << dis[min(k, n - 1)][x - 1][y - 1] << '\n';
  }
}
