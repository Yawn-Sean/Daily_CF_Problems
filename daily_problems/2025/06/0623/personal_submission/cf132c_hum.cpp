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

  string s;
  cin >> s;
  int n;
  cin >> n;
  int inf = 100000;
  vector dp(s.size(), vector(2, vector(n + 1, -inf)));
  function<int (int, int, int)> dfs = [&](int i, int d, int k) -> int {
    if (i == s.size()) {
      if (k % 2 == n % 2) {
        return 0;
      }
      return -inf;
    }
    if (k > n) {
      return -inf;
    }
    int &res = dp[i][d][k];
    if (res != -inf) {
      return res;
    }
    if (s[i] == 'F') {
      if (d == 1) {
        // not change
        res = max(res, dfs(i + 1, 1, k) + 1);
        // change
        res = max(res, dfs(i + 1, 0, k + 1));
      } else {
        // not change
        res = max(res, dfs(i + 1, 0, k) - 1);
        // change
        res = max(res, dfs(i + 1, 1, k + 1));
      }
    } else {
      if (d == 1) {
        // not change
        res = max(res, dfs(i + 1, 0, k));
        // change
        res = max(res, dfs(i + 1, 1, k + 1) + 1);
      } else {
        // not change
        res = max(res, dfs(i + 1, 1, k));
        // change
        res = max(res, dfs(i + 1, 0, k + 1) - 1);
      }
    }
    return res;
  };


  vector dp2(s.size(), vector(2, vector(n + 1, inf)));
  function<int (int, int, int)> dfs2 = [&](int i, int d, int k) -> int {
    if (i == s.size()) {
      if (k % 2 == n % 2) {
        return 0;
      }
      return inf;
    }
    if (k > n) {
      return inf;
    }
    int &res = dp2[i][d][k];
    if (res != inf) {
      return res;
    }
    if (s[i] == 'F') {
      if (d == 1) {
        // not change
        res = min(res, dfs2(i + 1, 1, k) + 1);
        // change
        res = min(res, dfs2(i + 1, 0, k + 1));
      } else {
        // not change
        res = min(res, dfs2(i + 1, 0, k) - 1);
        // change
        res = min(res, dfs2(i + 1, 1, k + 1));
      }
    } else {
      if (d == 1) {
        // not change
        res = min(res, dfs2(i + 1, 0, k));
        // change
        res = min(res, dfs2(i + 1, 1, k + 1) + 1);
      } else {
        // not change
        res = min(res, dfs2(i + 1, 1, k));
        // change
        res = min(res, dfs2(i + 1, 0, k + 1) - 1);
      }
    }
    return res;
  };

  cout << max(dfs(0, 1, 0), -dfs2(0, 1, 0)) << '\n';
}
