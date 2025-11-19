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

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<string> grid(n);
    for (auto &s: grid) cin >> s;

    vector<pair<int, int>> ops;
    vector vis(n, 0);

    auto dfs = [&](auto &self, int u) -> void {
      vis[u] = 1;

      for (int v = 0; v < n; v++) {
        if (grid[u][v] != '0' && !vis[v]) {
          ops.emplace_back(u, v);
          self(self, v);
        }
      }
    };

    dfs(dfs, 0);

    if (ops.size() + 1 == n) {
      cout << "Yes\n";
      ranges::reverse(ops);
      for (auto &[u, v]: ops)
        cout << u + 1 << ' ' << v + 1 << '\n';
    } else cout << "No\n";

    if (t) cout << '\n';
  }
}
