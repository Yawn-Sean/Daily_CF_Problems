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

  int n, k;
  cin >> n >> k;

  vector<int> v1(n * k), v2(n * k);
  for (auto &x: v1) cin >> x;
  for (auto &x: v2) cin >> x;

  vector<vector<int>> pos(n + 1);
  for (int i = n * k - 1; i >= 0; i--)
    pos[v2[i]].emplace_back(i);

  atcoder::segtree<int, op, e> seg(n * k);
  for (int i = 0; i < n * k; i++) {
    for (auto &j: pos[v1[i]]) {
      seg.set(j, max(seg.get(j), seg.prod(0, j) + 1));
    }
  }

  cout << seg.all_prod();
}
