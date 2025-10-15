#include <bits/stdc++.h>
using namespace std;

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
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  DSU dsu(26);
  vector<array<char, 2>> res;
  for (int i = 0; i < n; ++i) {
    int u = s[i] - 'a';
    int v = t[i] - 'a';
    if (dsu.merge(u, v)) {
      res.push_back({s[i], t[i]});
    }
  }
  cout << res.size() << '\n';
  for (auto [u, v]: res) {
    cout << u << ' ' << v << '\n';
  }
}
