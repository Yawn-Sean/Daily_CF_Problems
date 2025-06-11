#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, t;
  double p;
  cin >> n >> p >> t;
  int m = min(n, t);
  vector dp(t + 1, vector(m + 1, 0.0));
  dp[0][0] = 1;
  for (int i = 1; i <= t; ++i) {
    for (int j = 0; j < m; ++j) {
      dp[i][j] += dp[i - 1][j] * (1 - p);
      dp[i][j + 1] += dp[i - 1][j] * p;
    }
    dp[i][m] += dp[i - 1][m];
  }
  double res{};

  for (int i = 1; i <= m; i++) {
    res += i * dp[t][i];
  }
  cout << fixed << setprecision(10) << res << endl;
}
