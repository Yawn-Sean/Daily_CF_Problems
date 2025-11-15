#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1000000007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;

  vector<int> cubes(n);
  for (int i = 0; i < n; i++) {
    cin >> cubes[i];
  }

  vector<vector<int>> dp(n, vector<int>(n, 0));
  for (int len = 1; len < n; len++) {
    for (int l = 0; l + len < n; l++) {
      int r = l + len;

      dp[l][r] = dp[l + 1][r - 1];
      if (cubes[l] % cubes[r] == 0 || cubes[r] % cubes[l] == 0) {
        dp[l][r] += 2;
      }
      for (int sep = l; sep < r; sep++) {
        dp[l][r] = max(dp[l][r], dp[l][sep] + dp[sep + 1][r]);
      }
    }
  }

  vector<int> used(n);
  auto dfs = [&](auto&& self, int l, int r) -> void {
    if (l >= r) {
      return;
    }
    for (int sep = l; sep < r; sep++) {
      if (dp[l][r] == dp[l][sep] + dp[sep + 1][r]) {
        self(self, l, sep);
        self(self, sep + 1, r);
        return;
      }
    }
    if (cubes[l] % cubes[r] == 0 || cubes[r] % cubes[l] == 0) {
      used[l] = used[r] = 1;
      self(self, l + 1, r - 1);
    }
  };
  dfs(dfs, 0, n - 1);

  cout << n - dp[0][n - 1] << "\n";
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      cout << i + 1 << ' ';
    }
  }
  return 0;
}
