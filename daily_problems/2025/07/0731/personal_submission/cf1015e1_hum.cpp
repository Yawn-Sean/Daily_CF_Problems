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
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector vis(n, vector<int>(m));
  vector<array<int, 3>> res;
  auto in = [&](int u, int v, int cnt) {
    if (u - cnt < 0 || v - cnt < 0 || u + cnt >= n || v + cnt >= m) return 0;
    if (a[u + cnt][v] != '*' || a[u - cnt][v] != '*' || a[u][v + cnt] != '*' || a[u][v - cnt] != '*') return 0;
    return 1;
  };

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int cnt{1};
      if (a[i][j] == '*') {
        while (true) {
          if (in(i, j, cnt)) {
            vis[i][j] = 1;
            vis[i + cnt][j] = vis[i - cnt][j] = vis[i][j + cnt] = vis[i][j - cnt] = 1;
            cnt++;
          } else {
            if (cnt > 1) {
              res.push_back({i + 1, j + 1, cnt - 1});
            }
            break;
          }
        }
      }
    }
  }
  bool flg = true;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '*' && vis[i][j] == 0) {
        flg = false;
        break;
      }
    }
  }

  if (!flg) {
    cout << -1 << '\n';
  } else {
    cout << res.size() << '\n';
    for (auto &[i, j, k]: res) {
      cout << i << ' ' << j << ' ' << k << '\n';
    }
  }
}
