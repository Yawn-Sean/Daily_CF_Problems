#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1e9+7;
/*
很明显是个 DP 题。如何从小规模问题的解推出大规模的呢？

用了i+1个方块 最后一个是红色的方案数

dp[red][i+1] += dp[*][i] (所有红色)

多算的是 kr+1 个红色方块的方案数

-= dp[blue/green][i - kr] 

*/
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  i64 n, kr, kg, kb;
  cin >> n >> kr >> kg >> kb;

  // 叠buff
  vector<array<i64, 3>> dp(n + 1);
  dp[1] = {1, 1, 1};

  auto add = [&](i64 &x, i64 y) {
    x = (x + y) % mod;
  };

  for (int i = 2; i <= n; i++) {
    i64 tot = 0;
    add(tot, dp[i - 1][0]); // red
    add(tot, dp[i - 1][1]); // blue
    add(tot, dp[i - 1][2]); // green

    dp[i][0] = tot; // red
    if (i > kr + 1) {
      add(dp[i][0], mod - dp[i - kr - 1][1]); // blue
      add(dp[i][0], mod - dp[i - kr - 1][2]); // green
    } else if (i == kr + 1) {
      add(dp[i][0], mod - 1);
    }

    dp[i][1] = tot; // blue
    if (i > kb + 1) {
      add(dp[i][1], mod - dp[i - kb - 1][0]); // red
      add(dp[i][1], mod - dp[i - kb - 1][2]); // green
    } else if (i == kb + 1) {
      add(dp[i][1], mod - 1);
    }

    dp[i][2] = tot; // green
    if (i > kg + 1) {
      add(dp[i][2], mod - dp[i - kg - 1][0]); // red
      add(dp[i][2], mod - dp[i - kg - 1][1]); // blue
    } else if (i == kg + 1) {
      add(dp[i][2], mod - 1);
    }
  }

  i64 ans = 0;
  add(ans, dp[n][0]);
  add(ans, dp[n][1]);
  add(ans, dp[n][2]);
  cout << ans << endl;
  return 0;
}
