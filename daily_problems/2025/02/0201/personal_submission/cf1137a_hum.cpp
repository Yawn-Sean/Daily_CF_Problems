#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector a(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }
  vector<vector<int>> row(n);
  for (int i = 0; i < n; i++) {
    row[i] = vector(a[i]);
    ranges::sort(row[i]);
    row[i].erase(ranges::unique(row[i]).begin(), row[i].end());
  }
  vector<vector<int>> col(m);
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n; i++) {
      col[j].push_back(a[i][j]);
    }
    ranges::sort(col[j]);
    col[j].erase(ranges::unique(col[j]).begin(), col[j].end());
  }
  vector res(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int l1 = row[i].size();
      int x1 = ranges::lower_bound(row[i], a[i][j]) - row[i].begin();
      int l2 = col[j].size();
      int x2 = ranges::lower_bound(col[j], a[i][j]) - col[j].begin();
      res[i][j] = max(x1, x2) + max(l1 - x1, l2 - x2);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << res[i][j] << " \n"[j == m - 1];
    }
  }
}
