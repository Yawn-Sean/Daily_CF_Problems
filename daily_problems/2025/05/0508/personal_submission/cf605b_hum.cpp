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
  vector<array<int, 3>> a(m);
  for (int i = 0; i < m; i++) {
    a[i][0] = i;
    cin >> a[i][1] >> a[i][2];
  }
  ranges::sort(a, [](auto &l, auto &r) {
    if (l[1] != r[1]) {
      return l[1] < r[1];
    }
    return l[2] > r[2];
  });

  int from{2}, to{3}, cur{2};
  vector<array<int, 2>> res(m);
  for (int i = 0; i < m; i++) {
    if (a[i][2] == 1) {
      res[a[i][0]][0] = 1;
      res[a[i][0]][1] = cur++;
    } else {
      if (to >= cur) {
        cout << -1;
        return 0;
      }
      res[a[i][0]][0] = from++;
      res[a[i][0]][1] = to;
      if (from == to) {
        to++;
        from = 2;
      }
    }
  }
  for (int i = 0; i < m; i++) {
    cout << res[i][0] << " " << res[i][1] << '\n';
  }
}
