#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int x;
  vector<int> leaves;
  vector<bool> is_leaf(n);
  vector id(n, n + 5);
  while (cin >> x) {
    leaves.push_back(x - 1);
    id[x - 1] = leaves.size();
    is_leaf[x - 1] = true;
  }

  function<void(int, int)> dfs1 = [&](int u, int p) {
    for (int v: g[u]) {
      if (v == p) continue;
      dfs1(v, u);
      id[u] = min(id[u], id[v]);
    }
  };

  dfs1(0, 0);
  vector<int> res;
  bool f{true};
  ranges::reverse(leaves);
  function<void(int, int)> dfs2 = [&](int u, int p) {
    ranges::sort(g[u], [&](int a, int b) { return id[a] < id[b]; });
    res.push_back(u);
    if (is_leaf[u]) {
      if (res.back() != leaves.back()) {
        f = false;
      }
      leaves.pop_back();
    }
    for (int v: g[u]) {
      if (v == p) continue;
      dfs2(v, u);
      res.push_back(u);
    }
  };
  dfs2(0, 0);

  if (!f) {
    cout << "-1" << '\n';
  } else {
    for (int x: res) {
      cout << x + 1 << ' ';
    }
    cout << '\n';
  }
}
