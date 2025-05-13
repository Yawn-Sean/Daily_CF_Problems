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
  int n, k, x;
  cin >> n >> k >> x;

  vector<int> dp(1024), ndp(1024);

  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    dp[t]++;
  }

  while (k--) {
    int cnt{};
    for (int i = 0; i < 1024; i++) {
      if (dp[i]) {
        int a = dp[i] / 2;
        int b = dp[i] - a;
        if (cnt & 1) {
          ndp[i ^ x] += a;
          ndp[i] += b;
        } else {
          ndp[i ^ x] += b;
          ndp[i] += a;
        }
        cnt += dp[i];
      }
    }
    for (int i = 0; i < 1024; i++) {
      dp[i] = ndp[i];
      ndp[i] = 0;
    }
  }
  int l{1024}, r{};
  for (int i = 0; i < 1024; i++) {
    if (dp[i]) {
      l = min(i, l);
      r = max(i, r);
    }
  }
  cout << r << " " << l << '\n';
}
