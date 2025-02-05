#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int m = (n + 1) / 2;
  int inf = 1e9;
  vector dp(n, vector(m + 1, array<int, 2>({inf, inf})));

  dp[0][0][0] = dp[0][1][1] = 0;
  if (n >= 2) {
    dp[1][0][0] = 0;
    dp[1][1][0] = max(0, a[1] - a[0] + 1);
    dp[1][1][1] = max(0, a[0] - a[1] + 1);
  }


  for (int i = 2; i < n; i++) {
    for (int j = 0; j <= m; ++j) {
      dp[i][j][0] = min(dp[i - 1][j][0], dp[i - 1][j][1] + max(a[i] - a[i - 1] + 1, 0));
      if (j >= 1) {
        dp[i][j][1] = min(dp[i - 2][j - 1][0] + max(a[i - 1] - a[i] + 1, 0),
                          dp[i - 2][j - 1][1] + max(a[i - 1] - min(a[i], a[i - 2]) + 1, 0));
      }
    }
  }


  for (int i = 1; i <= m; i++) {
    cout << min(dp[n - 1][i][0], dp[n - 1][i][1]) << " ";
  }
}
