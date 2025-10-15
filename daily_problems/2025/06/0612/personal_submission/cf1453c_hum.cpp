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
    int n;
    cin >> n;

    vector<string> grid(n);
    for (auto &s: grid) cin >> s;

    vector<int> min_x(10, n + 1), max_x(10, -1);
    vector<int> min_y(10, n + 1), max_y(10, -1);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int v = grid[i][j] - '0';
        min_x[v] = min(min_x[v], i);
        max_x[v] = max(max_x[v], i);
        min_y[v] = min(min_y[v], j);
        max_y[v] = max(max_y[v], j);
      }
    }

    vector res(10, 0);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int v = grid[i][j] - '0';
        res[v] = max(res[v], max(i, n - 1 - i) * max(max_y[v] - j, j - min_y[v]));
        res[v] = max(res[v], max(j, n - 1 - j) * max(max_x[v] - i, i - min_x[v]));
      }
    }

    for (auto &x: res) {
      cout << x << ' ';
    }
    cout << endl;
  }
}
