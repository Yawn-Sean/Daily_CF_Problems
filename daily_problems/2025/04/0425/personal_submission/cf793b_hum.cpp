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
  vector a(n, vector<char>(m));
  int x1{}, y1{}, x2{}, y2{};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      if (a[i][j] == 'S') {
        x1 = i, y1 = j;
      }
      if (a[i][j] == 'T') {
        x2 = i, y2 = j;
      }
    }
  }
  queue<array<int, 4>> que;
  vector vis(n, vector(m, vector(4, vector(3, 0))));
  for (int i = 0; i < 4; i++) {
    que.push({x1, y1, i, 0});
  }
  vector<vector<int>> f{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  while (!que.empty()) {
    auto [x, y, d, c] = que.front();
    que.pop();

    if (vis[x][y][d][c]) {
      continue;
    }
    vis[x][y][d][c] = 1;
    for (int i = 0; i < 4; i++) {
      array nxt = {x + f[i][0], y + f[i][1], i, c + (i != d)};
      if (0 <= nxt[0] && nxt[0] < n && 0 <= nxt[1] && nxt[1] < m && a[nxt[0]][nxt[1]] != '*' && nxt[3] <= 2) {
        if (nxt[0] == x2 && nxt[1] == y2) {
          cout << "YES" << endl;
          return 0;
        }
        que.push(nxt);
      }
    }
  }
  cout << "NO" << endl;
}
