/*
  https://codeforces.com/problemset/problem/780/C
  kaicheng
  2025-05-16
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define mod 1000000007 // 10^9 + 7
#define MOD 998244353  // 998244353

#define YES cout << "YES" << '\n'
#define NO cout << "NO" << '\n'
#define int long long
#define itn int

void solve() {
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

  vector<int> color(n, 0);
  int max_color = 1;
  color[0] = 1; // root

  auto dfs = [&](auto &self, int u, int cnt) -> void {
    int available = 1;
    for (int v : g[u]) {
      if (v == cnt)
        continue;
      while (available == color[u] || (cnt != -1 && available == color[cnt])) {
        available++;
      }
      color[v] = available++;
      max_color = max(max_color, color[v]);
      self(self, v, u);
    }
  };

  dfs(dfs, 0, -1);

  cout << max_color << endl;
  for (int c : color) {
    cout << c << " ";
  }
  cout << endl;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt = 1;
  // cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}