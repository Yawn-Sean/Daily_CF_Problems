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

  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<long long> f(n), s(n);
  function<void(int, int)> dfs = [&](int u, int p) {
    for (int v: g[u]) {
      if (v != p) {
        dfs(v, u);
        f[u] = max(f[u], f[v]);
        s[u] = max(s[u], s[v]);
      }
    }
    int k = a[u] + f[u] - s[u];
    if (k > 0) {
      s[u] += k;
    } else {
      f[u] += -k;
    }
  };
  dfs(0, 0);

  cout << f[0] + s[0] << endl;
}
