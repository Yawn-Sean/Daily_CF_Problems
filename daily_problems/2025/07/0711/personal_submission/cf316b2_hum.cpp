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

  int n, p;
  cin >> n >> p;
  p--;
  vector<int> a(n);
  DSU dsu(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a[i]--;
    if (a[i] != -1) {
      dsu.merge(i, a[i]);
    }
  }
  int x = dsu.find(p);
  vector<int> v;
  for (int i = 0; i < n; i++) {
    if (dsu.find(i) == i && i != x) {
      v.push_back(dsu.size(i));
    }
  }
  int pos{1};
  while (a[p] != -1) {
    p = a[p];
    pos++;
  }
  vector<bool> dp(n);
  dp[0] = true;
  for (int i: v) {
    for (int j = n - 1; j >= 0; --j) {
      if (j - i >= 0) {
        dp[j] = dp[j] | dp[j - i];
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (dp[i]) {
      cout << i + pos << endl;
    }
  }
}
