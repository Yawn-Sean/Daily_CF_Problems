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

  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> p(m);
  vector<int> ans(m);
  for (auto &[x, y]: p) cin >> x >> y, x--, y--; {
    vector<vector<pair<int, int>>> a(n);
    for (int i = 0; i < m; i++) {
      auto [x, y] = p[i];
      a[x].emplace_back(y, i);
    }
    for (int i = 0; i < n; i++) {
      if (a[i].size() < 2) continue;
      ranges::sort(a[i]);
      for (int j = 1; j < a[i].size(); j++) {
        ans[a[i][j].second]++;
        ans[a[i][j - 1].second]++;
      }
    }
  } {
    vector<vector<pair<int, int>>> a(n);
    for (int i = 0; i < m; i++) {
      auto [x, y] = p[i];
      a[y].emplace_back(x, i);
    }
    for (int i = 0; i < n; i++) {
      if (a[i].size() < 2) continue;
      ranges::sort(a[i]);
      for (int j = 1; j < a[i].size(); j++) {
        ans[a[i][j].second]++;
        ans[a[i][j - 1].second]++;
      }
    }
  } {
    // [-n + 1, n - 1]
    vector<vector<pair<int, int>>> a(2 * n);
    for (int i = 0; i < m; i++) {
      auto [x, y] = p[i];
      a[x - y + n].emplace_back(y, i);
    }
    for (int i = 0; i < 2 * n; i++) {
      if (a[i].size() < 2) continue;
      ranges::sort(a[i]);
      for (int j = 1; j < a[i].size(); j++) {
        ans[a[i][j].second]++;
        ans[a[i][j - 1].second]++;
      }
    }
  } {
    vector<vector<pair<int, int>>> a(2 * n);
    for (int i = 0; i < m; i++) {
      auto [x, y] = p[i];
      a[x + y].emplace_back(y, i);
    }
    for (int i = 0; i < 2 * n; i++) {
      if (a[i].size() < 2) continue;
      ranges::sort(a[i]);
      for (int j = 1; j < a[i].size(); j++) {
        ans[a[i][j].second]++;
        ans[a[i][j - 1].second]++;
      }
    }
  }
  vector<int> f(9);
  for (int i: ans) f[i]++;
  for (int i: f) cout << i << ' ';
  return 0;
}
