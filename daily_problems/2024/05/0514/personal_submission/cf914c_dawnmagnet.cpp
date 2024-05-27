#include <bits/stdc++.h>
#define REP(i, j) for (int i = 0; i < j; ++i)
using namespace std;
using ll = int64_t;
const int MOD = 1e9 + 7;

int cost[1500];
int dp[1005][1005] = {1};
int solve() {

  for (int i = 2; i <= 1024; ++i) {
    cost[i] = cost[__builtin_popcount(i)] + 1;
    // cout << cost[i] << ' ';
  }
  // cout << endl;
  int res = 0;
  int k;
  string st;
  cin >> st >> k;

  if (k == 0)
    return 1;

  int prev = 0, sum = 0;
  for (int i = 1; i <= st.size(); ++i) {
    for (int j = 0; j < i; ++j) {
      dp[i][j] += dp[i - 1][j];
      dp[i][j] %= MOD;
      dp[i][j + 1] += dp[i - 1][j];
      dp[i][j + 1] %= MOD;
    }
    if (st[i - 1] == '1') {
      sum++;
    } else {
      dp[i][sum + 1]--;
    }
  }
  REP(i, 1024) {
    if (k == 1 && i < 1)
      continue;
    if (cost[i] + 1 == k) {
      res += dp[st.size()][i];
      res %= MOD;
    }
  }
  if (k == 1)
    res--;
  // REP(i, 10) REP(j, 10) if (dp[i][j]) printf("%d %d %d\n", i, j, dp[i][j]);
  return res;
}
int main() {
  //   int T;
  //   cin >> T;
  //   while (T--) {
  cout << solve();
  //   }
}