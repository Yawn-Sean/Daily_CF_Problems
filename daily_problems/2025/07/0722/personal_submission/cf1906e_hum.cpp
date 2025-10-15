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

  int n;
  cin >> n;
  vector<int> a(2 * n);
  for (int i = 0; i < 2 * n; ++i) {
    cin >> a[i];
  }
  vector<array<int, 2>> t;
  for (int i = 0; i < 2 * n; i++) {
    int j = i;
    while (j + 1 < n * 2 && a[j + 1] < a[i]) {
      j++;
    }
    t.push_back({i, j});
    i = j;
  }
  vector dp(t.size() + 1, vector(n + 1, 0));
  dp[0][0] = 1;
  for (int i = 0; i < t.size(); i++) {
    int l = t[i][1] - t[i][0] + 1;
    for (int j = n; j >= 0; j--) {
      dp[i + 1][j] = dp[i][j];
      if (j - l >= 0) {
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - l]);
      }
    }
  }

  if (!dp[t.size()][n]) {
    cout << -1 << endl;
    return 0;
  }

  vector<int> col(n * 2);

  int u{n};
  int idx = t.size() - 1;
  while (idx >= 0) {
    auto [l, r] = t[idx];
    if (u - (r - l + 1) >= 0 && dp[idx][u - (r - l + 1)]) {
      u -= r - l + 1;
      for (int j = l; j <= r; j++) {
        col[j] = 1;
      }
    }
    idx--;
  }

  for (int i = 0; i < 2 * n; i++) {
    if (!col[i]) {
      cout << a[i] << " ";
    }
  }
  cout << endl;
  for (int i = 0; i < 2 * n; i++) {
    if (col[i]) {
      cout << a[i] << " ";
    }
  }
}
