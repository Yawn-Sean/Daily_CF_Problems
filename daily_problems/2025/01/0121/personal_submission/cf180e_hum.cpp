#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n);
  vector<vector<int>> pos(m);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a[i]--;
    pos[a[i]].push_back(i);
  }

  int res = 0;
  for (int v = 0; v < m; v++) {
    int len = pos[v].size();
    int j = -1;
    for (int i = 0; i < len; ++i) {
      while (j + 1 < len && pos[v][j + 1] - pos[v][i] - (j + 1 - i) <= k) {
        j++;
      }
      res = max(res, j - i + 1);
    }
  }
  cout << res << "\n";
}
