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
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector g(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> g[i][j];
      }
    }
    int res1{}, res2{};
    for (int i = 0; i < m; i++) {
      res1 += abs(g[0][i] - g[n - 1][i]);
      res2 += abs(g[n / 2 - 1][i] - g[n / 2][i]);
    }
    if (res1 > res2) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
}
