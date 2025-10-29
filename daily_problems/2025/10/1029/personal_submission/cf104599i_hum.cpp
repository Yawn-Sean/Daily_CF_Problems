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
  vector<int> a(n), p(n), dp(n);
  vector<vector<int>> g(n);
  for (int i = 0; i < n; i++)cin >> a[i];
  for (int i = 1; i < n; i++) {
    cin >> p[i];
    g[p[i] - 1].emplace_back(i);
  }
  int ans = 0;
  function<void(int)> dfs = [&](int u)-> void {
    dp[u] = a[u];
    for (int v: g[u]) {
      dfs(v);
      ans = max(ans, dp[u] + dp[v] + 1);
      dp[u] = max(dp[u], dp[v] + 1);
    }
  };
  dfs(0);
  cout << ans << '\n';
}
