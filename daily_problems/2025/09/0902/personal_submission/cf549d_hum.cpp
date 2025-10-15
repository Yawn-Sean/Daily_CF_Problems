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
  vector<string> g(n);
  for (int i = 0; i < n; i++) {
    cin >> g[i];
  }
  int res{};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int x = g[i][j];
      if (i + 1 < n)x -= g[i + 1][j];
      if (j + 1 < m)x -= g[i][j + 1];
      if (i + 1 < n && j + 1 < m)x += g[i + 1][j + 1];

      if (x) {
        res++;
      }
    }
  }
  cout<<res<<'\n';
}
