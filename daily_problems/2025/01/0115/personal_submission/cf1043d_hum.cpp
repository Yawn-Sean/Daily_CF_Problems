#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
  int n, m;
  cin >> n >> m;
  vector a(m, vector<int>(n)), pos(m, vector<int>(n));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      a[i][j]--;
      pos[i][a[i][j]] = j;
    }
  }

  i64 res = 0;
  int r;
  for (int l = 0; l < n; l = r + 1) {
    r = l;
    while (r + 1 < n) {
      bool ok = true;
      for (int i = 1; i < m; i++) {
        if (pos[i][a[0][r + 1]] - pos[i][a[0][r]] != 1) {
          ok = false;
          break;
        }
      }
      if (!ok) {
        break;
      }
      r++;
    }
    res += 1ll * (r - l + 1) * (r - l + 2) / 2;
  }
  cout << res << endl;
}
