#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

struct DSU {
  vector<int> f, siz;

  DSU() {
  }

  DSU(int n) {
    init(n);
  }

  void init(int n) {
    f.resize(n);
    ranges::iota(f, 0);
    siz.assign(n, 1);
  }

  int find(int x) {
    while (x != f[x]) {
      x = f[x] = f[f[x]];
    }
    return x;
  }

  bool same(int x, int y) {
    return find(x) == find(y);
  }

  bool merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) {
      return false;
    }
    siz[x] += siz[y];
    f[y] = x;
    return true;
  }

  int size(int x) {
    return siz[find(x)];
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;

  vector<int> nums(n);
  for (auto &x: nums) cin >> x;

  vector<pair<int, int>> edges(m);
  for (auto &[u, v]: edges)
    cin >> u >> v, u--, v--;


  vector ans(n, string(n, '0'));

  for (int i = 0; i < 30; i++) {
    DSU uf(n);
    for (auto &[u, v]: edges) {
      if ((nums[u] >> i & 1) && (nums[v] >> i & 1)) {
        uf.merge(u, v);
      }
    }
    for (int u = 0; u < n; u++) {
      for (int v = 0; v < n; v++) {
        if (uf.find(u) == uf.find(v)) {
          ans[u][v] = '1';
        }
      }
    }
  }

  for (auto &x: ans) cout << x << '\n';
}
