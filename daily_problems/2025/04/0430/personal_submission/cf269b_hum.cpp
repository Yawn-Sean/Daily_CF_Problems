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
  vector<int> nums(n);
  string s;

  for (int i = 0; i < n; i++) {
    cin >> nums[i] >> s;
  }

  vector dp(n, 1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (nums[j] <= nums[i]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }

  cout << n - ranges::max(dp);
}
