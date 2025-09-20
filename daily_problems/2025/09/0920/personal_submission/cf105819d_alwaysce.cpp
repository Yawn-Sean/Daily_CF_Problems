#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 MOD = 1000000007;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;

  vector<int> color(n);
  for (int i = 0; i < n; i++) {
    cin >> color[i];
  }

  vector<vector<int>> path(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;v--;
    path[u].push_back(v);
    path[v].push_back(u);
  }

  vector<vector<int>> ans(n, vector<int>(n, 0));
  for (int c = 0; c < 30; c++) {
    DSU dsu(n);
    for (int u = 0; u < n; u++) {
      for (auto& v : path[u]) {
        if (((color[u] >> c) & 1) == 1 && ((color[v] >> c) & 1) == 1) {
          dsu.merge(u, v);
        }
      }
    }

    for (int u = 0; u < n; u++) {
      for (int v = 0; v < n; v++) {
        if (dsu.same(u, v)) {
          ans[u][v] = 1;
        }
      }
    }
  }
  

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << ans[i][j];
    }
    cout << endl;
  }
  return 0;
}
