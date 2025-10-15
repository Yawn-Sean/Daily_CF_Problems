#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 MOD = 1000000007;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  vector<vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int fi;
    cin >> fi;
    g[fi].push_back(i);
  }
  
  // dp0: 子树内有一个值未知
  // dp1: 所有的值都已知
  auto dfs = [&](auto&& dfs, int u) -> pair<i64, i64> {
    if (g[u].size() == 0) {
      return {1ll, 1ll};
    }

    i64 dp0 = 0, dp1 = 1;
    for (auto& v : g[u]) {
      auto [v0, v1] = dfs(dfs, v);
      // 有一个节点未知
      dp0 = (dp1 * v0 % MOD + dp0 * v1 % MOD) % MOD;
      // 所有节点已知
      dp1 = dp1 * v1 % MOD;
    }

    // 有一个未知/所有的已知
    return {dp0, (dp0 + dp1) % MOD};
  };

  auto [ans0, ans1] = dfs(dfs, 1);
  cout << ans1 % MOD << endl;
  return 0;
}
