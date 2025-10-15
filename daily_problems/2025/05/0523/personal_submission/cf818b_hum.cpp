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

  vector<int> a(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i];
    a[i]--;
  }

  vector<int> vis(n + 1, -1), res(n, -1);

  for (int i = 1; i < m; i++) {
    int pos = a[i - 1];
    int step = (a[i] - a[i - 1] + n - 1) % n + 1;

    if (vis[step] != -1 && vis[step] != pos)
      return cout << -1, 0;
    if (res[pos] != -1 && res[pos] != step)
      return cout << -1, 0;

    vis[step] = pos, res[pos] = step;
  }

  int pt = 1;

  for (int i = 0; i < n; i++) {
    if (res[i] == -1) {
      while (vis[pt] != -1) pt++;
      res[i] = pt, vis[pt] = i;
    }
  }

  for (auto &x: res) cout << x << ' ';
}
