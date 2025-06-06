#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<vector<array<int, 2>>> g(n);
    for (int i = 0; i < m; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      a--, b--;
      g[a].push_back({b, c});
      g[b].push_back({a, -c});
    }
    long long inf = 1e15;
    vector dis(n, inf);
    bool res{true};
    function<void(int)> dfs = [&](int u) {
      for (auto [v, w]: g[u]) {
        if (dis[v] == inf) {
          dis[v] = dis[u] + w;
          dfs(v);
        } else if (dis[v] != dis[u] + w) {
          res = false;
        }
      }
    };


    for (int i = 0; i < n; i++) {
      if (dis[i] == inf) {
        dis[i] = 0;
        dfs(i);
      }
    }
    if (!res) {
      cout << "No\n";
    } else {
      cout << "Yes\n";
    }
  }
}

