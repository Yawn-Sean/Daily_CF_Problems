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

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i]--;
    }
    DSU dsu(n);
    set<array<int, 2>> st;
    vector<int> deg(n);
    for (int i = 0; i < n; i++) {
      int u = i, v = a[i];
      if (u > v) swap(u, v);
      if (!st.contains({u, v})) {
        st.insert({u, v});
        dsu.merge(u, v);
        deg[u]++, deg[v]++;
      }
    }
    int cnt1{}, cnt2{};
    for (int i = 0; i < n; i++) {
      if (i == dsu.find(i)) {
        cnt1++;
      }
      if (deg[i] == 1) {
        cnt2++;
      }
    }

    cout << cnt1 - max(0, (cnt2 / 2 - 1)) << " " << cnt1 << '\n';
  }
}
