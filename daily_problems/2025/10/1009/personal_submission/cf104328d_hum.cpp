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

  int M = 1e7;
  vector<int> prime_factor(M + 1);
  iota(prime_factor.begin(), prime_factor.end(), 0);

  for (int i = 2; i <= M; i++) {
    if (prime_factor[i] == i) {
      for (int j = i; j <= M; j += i) {
        prime_factor[j] = i;
      }
    }
  }

  int n;
  cin >> n;

  vector<int> nums(n);
  for (auto &x: nums) cin >> x;

  vector<vector<int>> path(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    path[u].emplace_back(v);
    path[v].emplace_back(u);
  }
  vector<int> cnt(M + 1, 0);

  for (auto &x: nums) {
    int vx = x;
    while (vx > 1) {
      int p = prime_factor[vx];
      cnt[p]++;
      while (vx % p == 0) vx /= p;
    }
  }
  int to_check, max_len;
  vector<int> dp(n);

  auto dfs = [&](auto &self, int u, int p) -> void {
    int v1 = 0, v2 = 0;

    for (auto &v: path[u]) {
      if (v != p) {
        self(self, v, u);
        if (dp[v] > v1) swap(v1, v2), v1 = dp[v];
        else if (dp[v] > v2) v2 = dp[v];
      }
    }

    if (nums[u] % to_check == 0) {
      max_len = max(max_len, v1 + v2 + 1);
      dp[u] = v1 + 1;
    }
  };

  for (int i = 0; i <= M; i++) {
    if (cnt[i] * 2 > n) {
      to_check = i, max_len = 0;
      dfs(dfs, 0, -1);
      if (max_len * 2 > n) return cout << "YES", 0;
    }
  }

  cout << "NO";
}
