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

  string s, pattern = "cdhs";
  cin >> s;

  int ans = 0;

  do {
    vector<int> dp(4, 0);
    for (auto &c: s) {
      for (int i = 0; i < 4; i++) {
        if (pattern[i] == c) dp[i]++;
      }
      dp[1] = max(dp[1], dp[0]);
      dp[2] = max(dp[2], dp[1]);
      dp[3] = max(dp[3], dp[2]);
    }
    ans = max(ans, dp[3]);
  } while (ranges::next_permutation(pattern).found);

  cout << s.size() - ans;
}
