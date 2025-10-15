#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> path(n);
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      --u;
      --v;
      path[u].push_back(v);
      path[v].push_back(u);
    }
    vector<int> color(n, -1), v0, v1;
    bool cant = true;
    auto dfs = [&](auto &&self, int u) -> void {
      if (color[u] == 0) {
        v0.push_back(u);
      } else {
        v1.push_back(u);
      }

      for (auto &v : path[u]) {
        if (color[v] == -1) {
          color[v] = color[u] ^ 1;
          self(self, v);
        } else if (color[u] == color[v]) {
          cant = false;
        }
      }
    };

    color[0] = 0;
    dfs(dfs, 0);

    if (!cant) {
      cout << "Alice" << endl;
      for (int i = 0; i < n; i++) {
        cout << 1 << ' ' << 2 << endl;
        int idx, val;
        cin >> idx >> val;
      }
    } else {
      cout << "Bob" << endl;
      for (int i = 0; i < n; i++) {
        int c1, c2;
        cin >> c1 >> c2;
        if ((c1 == 1 || c2 == 1) && v0.size() > 0) {
          int v = v0.back();
          v0.pop_back();
          cout << v + 1 << ' ' << 1 << endl;
        } else if ((c1 == 2 || c2 == 2) && v1.size() > 0) {
          int v = v1.back();
          v1.pop_back();
          cout << v + 1 << ' ' << 2 << endl;
        } else if (v0.size() > 0) {
          int v = v0.back();
          v0.pop_back();
          cout << v + 1 << ' ' << 3 << endl;
        } else {
          int v = v1.back();
          v1.pop_back();
          cout << v + 1 << ' ' << 3 << endl;
        }
      }
    }
  }

  return 0;
}
