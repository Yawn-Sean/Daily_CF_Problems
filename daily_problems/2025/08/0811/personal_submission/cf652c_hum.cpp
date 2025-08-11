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
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    x--;
    p[x] = i;
  }
  vector<int> r(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    x = p[x], y = p[y];
    if (x > y) swap(x, y);
    r[y] = max(r[y], x + 1);
  }

  long long res{};
  int l = 0;
  for (int i = 0; i < n; i++) {
    l = max(l, r[i]);
    res += i - l + 1;
  }
  cout << res << '\n';
}
