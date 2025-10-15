/* #pragma GCC optimize(2) */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define Debug(x) cout << #x << ':' << x << endl
#define all(x) (x).begin(), (x).end()

const int INF = 1e9;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> grid(n);
  for (int i = 0; i < n; i++) {
    cin >> grid[i];
  }

  int sx = -1, sy = -1, tx = -1, ty = -1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 'S') {
        sx = i;
        sy = j;
      }
      if (grid[i][j] == 'T') {
        tx = i;
        ty = j;
      }
    }
  }

  vector<vector<array<int, 4>>> dist(n, vector<array<int, 4>>(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      for (int d = 0; d < 4; d++)
        dist[i][j][d] = INF;

  deque<tuple<int, int, int>> dq;
  for (int d = 0; d < 4; d++) {
    dist[sx][sy][d] = 0;
    dq.emplace_back(sx, sy, d);
  }

  while (!dq.empty()) {
    auto [x, y, dir] = dq.front();
    dq.pop_front();
    int cur = dist[x][y][dir];
    if (cur > 2)
      continue;

    for (int nd = 0; nd < 4; nd++) {
      int nx = x + dx[nd], ny = y + dy[nd];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m)
        continue;
      if (grid[nx][ny] == '*')
        continue;

      int w = (nd == dir ? 0 : 1);
      if (cur + w < dist[nx][ny][nd] && cur + w <= 2) {
        dist[nx][ny][nd] = cur + w;
        if (w == 0)
          dq.emplace_front(nx, ny, nd);
        else
          dq.emplace_back(nx, ny, nd);
      }
    }
  }

  bool ok = false;
  for (int d = 0; d < 4; d++) {
    if (dist[tx][ty][d] <= 2) {
      ok = true;
      break;
    }
  }
  cout << (ok ? "YES" : "NO") << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}
