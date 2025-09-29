#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;

  vector<vector<int>> path(n, vector<int>(n, 0));
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;

    path[u][v] = 1;
    path[v][u] = 1;
  }

  int col = 0;
  vector<int> color(n, -1);
  function<void(int)> dfs = [&](int u) {
    color[u] = col;
    for (int v = 0; v < n; v++) {
      if (path[u][v] == 0 && color[v] == -1) {
        dfs(v);
      }
    }
  };

  for (int i = 0; i < n; i++) {
    if (color[i] == -1) {
      dfs(i);
      col++;
    }
  }

  if (col > k) {
    cout << "-1\n";
    return 0;
  }

  bool valid = true;
  for (int u = 0; u < n; u++) {
    for (int v = 0; v < n; v++) {
      if (path[u][v] == 1 && (color[u] == color[v])) {
        valid = false;
        break;
      }
      if (path[u][v] == 0 && (color[u] != color[v])) {
        valid = false;
        break;
      }
    }
  }

  if (!valid) {
    cout << "-1\n";
    return 0;
  }

  for (int i = 0; i < n; i++) {
    cout << color[i] + 1 << ' ';
  }
  cout << '\n';

  return 0;
}
