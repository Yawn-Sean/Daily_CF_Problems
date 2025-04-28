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
  vector a(n, vector<char>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  DSU dsu(n * m);
  vector<array<int, 2>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '.') {
        for (auto [dx,dy]: dirs) {
          int x = i + dx, y = j + dy;
          if (x >= 0 && x < n && y >= 0 && y < m && a[x][y] == '.') {
            dsu.merge(i * m + j, x * m + y);
          }
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '*') {
        set<int> st{};
        for (auto [dx,dy]: dirs) {
          int x = i + dx, y = j + dy;
          if (x >= 0 && x < n && y >= 0 && y < m && a[x][y] == '.') {
            st.insert(dsu.find(x * m + y));
          }
        }
        int res{1};
        for (int x: st) {
          res += dsu.size(x);
        }
        a[i][j] = (char) ('0' + res % 10);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << a[i][j];
    }
    cout << endl;
  }
}
