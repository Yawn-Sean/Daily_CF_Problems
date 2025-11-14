#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1000000007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }
  sort(nums.begin(), nums.end());

  i64 ans = 0;
  int MX = 1e4 + 1;
  vector<vector<i64>> dp(k + 1, vector<i64>(MX + 1));

  dp[0][0] = 1;
  int cur = 0;
  for (int i = 0; i < n; i++) {
    // 前面选了j个物品 它们的和为w的方案数
    for (int j = min(i, k - 1); j >= 0; j--) {
      for (int w = 0; w <= min(cur, MX); w++) {
        int nw = w + nums[i];
        nw = min(nw, MX);
        dp[j + 1][nw] += dp[j][w];
        dp[j + 1][nw] %= mod;
      }
      if (j + 1 == k) {
        for (int w = nums[i] + 1; w <= MX; w++) {
          ans = (ans + dp[j][w]) % mod;
        }
      }
    }
    cur += nums[i];
  }
  cout << ans << "\n";
  return 0;
}
