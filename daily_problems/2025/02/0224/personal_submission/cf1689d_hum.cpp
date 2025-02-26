#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for (int i = 0; i < n; i++) {
      cin >> g[i];
    }
    int mx1 = -5000, mi1 = 5000, mx2 = -5000, mi2 = 5000;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (g[i][j] == 'B') {
          mx1 = max(mx1, i + j);
          mi1 = min(mi1, i + j);
          mx2 = max(mx2, i - j);
          mi2 = min(mi2, i - j);
        }
      }
    }
    array res{5000, -1, -1};
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int tmp = max({mx1 - i - j, i + j - mi1, mx2 - i + j, i - j - mi2});
        if (tmp < res[0]) {
          res = {tmp, i, j};
        }
      }
    }
    cout << res[1] + 1 << " " << res[2] + 1 << "\n";
  }
}
