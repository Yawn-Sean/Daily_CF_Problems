#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
      cin >> grid[i];
    }

    // 根据1进行建图
    // 确保从1顶点开始进行有向图上的遍历

    vector<int> vis(n);
    vector<pair<int, int>> ans;
    auto dfs = [&](auto&& dfs, int u) -> void {
      vis[u] = 1;
      for (int v = 0; v < n; v++) {
        if (grid[u][v] != '0' && !vis[v]) {
          vis[v] = 1;
          ans.emplace_back(u + 1, v + 1);
          dfs(dfs, v);
        }
      }
    };

    dfs(dfs, 0);
    if (ans.size() != n - 1) {
      cout << "No\n";
    } else {
      cout << "Yes\n";
      reverse(ans.begin(), ans.end());
      for (const auto& [u, v] : ans) {
        cout << u << ' ' << v << '\n';
      }
    }
  }
  return 0;
}
