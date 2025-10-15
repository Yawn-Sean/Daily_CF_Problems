#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    for (int i = 0; i < k; ++i) {
      cin >> a[i];
      a[i]--;
    }
    vector g(n, vector<int>());
    for (int i = 0; i < n - 1; ++i) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }

    vector<int> path, vis(n);

    function<void(int, int)> dfs1 = [&](int u, int p) -> void {
      path.push_back(u);
      vis[u] = path[path.size() / 2];
      for (int v: g[u]) {
        if (v == p) continue;
        dfs1(v, u);
      }
      path.pop_back();
    };

    dfs1(0, 0);
    vector control(n, 0);
    for (int p: a) {
      control[vis[p]] = 1;
    }

    int res{};
    function<void(int, int)> dfs2 = [&](int u, int p) -> void {
      if (control[u]) {
        res++;
        return;
      }
      if (u != 0 && g[u].size() == 1) {
        res = n + 5;
        return;
      }

      for (int v: g[u]) {
        if (v == p) continue;
        dfs2(v, u);
      }
    };

    dfs2(0, 0);
    if (res <= n) {
      cout << res << endl;
    } else {
      cout << -1 << endl;
    }
  }
}
