#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<array<int, 3>> a(m);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    a[i] = {w, u - 1, v - 1};
  }

  ranges::sort(a.begin() + 1, a.end());

  DSU dsu(n);
  int x = a[0][1], y = a[0][2];
  for (int i = 1; i < m; i++) {
    int u = a[i][1], v = a[i][2];
    if (dsu.merge(u, v)) {
      if (dsu.same(x, y)) {
        cout << a[i][0] << '\n';
        return 0;
      }
    }
  }
  cout << 1000000000 << '\n';
}
