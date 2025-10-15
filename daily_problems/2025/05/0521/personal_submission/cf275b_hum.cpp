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
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<array<int, 2>> tmp;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 'B') {
        tmp.push_back({i, j});
      }
    }
  }

  for (int i = 0; i < tmp.size(); i++) {
    for (int j = 0; j < i; j++) {
      if (tmp[i][0] == tmp[j][0]) {
        int l = min(tmp[i][1], tmp[j][1]);
        int r = max(tmp[i][1], tmp[j][1]);
        for (int k = l; k <= r; k++) {
          if (a[tmp[i][0]][k] != 'B') {
            cout << "NO" << endl;
            return 0;
          }
        }
      } else if (tmp[i][1] == tmp[j][1]) {
        int l = min(tmp[i][0], tmp[j][0]);
        int r = max(tmp[i][0], tmp[j][0]);
        for (int k = l; k <= r; k++) {
          if (a[k][tmp[i][1]] != 'B') {
            cout << "NO" << endl;
            return 0;
          }
        }
      } else if (a[tmp[i][0]][tmp[j][1]] != 'B' && a[tmp[j][0]][tmp[i][1]] != 'B') {
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  cout << "YES" << endl;
}
