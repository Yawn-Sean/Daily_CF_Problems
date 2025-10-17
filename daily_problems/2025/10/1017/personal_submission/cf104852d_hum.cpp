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

  set<int> vis;
  vis.insert(0);

  int bound = 1e9;
  auto dfs = [&](auto &self, int x, int y, long long cur) -> void {
    if (cur > bound) return;
    vis.insert(cur);
    self(self, x, y, 10 * cur + x);
    self(self, x, y, 10 * cur + y);
  };

  for (int i = 1; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      dfs(dfs, i, j, i);
    }
  }

  int n;
  cin >> n;

  int ans = 0;
  for (auto &x: vis) {
    if (vis.find(n - x) != vis.end()) {
      ans++;
    }
  }

  cout << (ans + 1) / 2;
}
