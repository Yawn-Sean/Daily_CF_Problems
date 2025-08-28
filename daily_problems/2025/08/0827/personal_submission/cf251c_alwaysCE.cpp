#include <bits/stdc++.h>
using namespace std;
using i64 = long long;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  i64 a, b, k;
  cin >> a >> b >> k;
  int inf = 1e9;
  int lcm = 360360;

  i64 ans = 0;
  // between different blocks
  if (a / lcm != b / lcm) {
    vector<int> dp(lcm + 1, inf);
    dp[0] = 0;
    for (int i = 1; i <= lcm; i++) {
      dp[i] = min(dp[i], dp[i - 1] + 1);
      for (int j = 2; j <= k; j++) {
        dp[i] = min(dp[i], dp[i - (i % j)] + 1);
      }
    }

    ans += dp[a % lcm];
    a -= (a % lcm);

    i64 gap = (a - b) / lcm;
    ans += gap * dp[lcm];
    a -= gap * lcm;

    // reached the point
    a--;
    ans++;
  }

  // now a and b are in the same block
  a %= lcm;
  b %= lcm;
  {
    vector<int> dp(lcm + 1, inf);
    dp[b] = 0;
    for (int i = b + 1; i <= a; i++) {
      dp[i] = min(dp[i], dp[i - 1] + 1);
      for (int j = 2; j <= k; j++) {
        dp[i] = min(dp[i], dp[i - (i % j)] + 1);
      }
    }

    ans += dp[a];
  }
  cout << ans << endl;
  return 0;
}
