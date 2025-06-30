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

  int k;
  cin >> k;
  int n = s.size();

  vector cost(n + 1, vector<int>(n + 1));
  for (int i = n; i; i--) {
    for (int j = i + 1; j <= n; j++) {
      cost[i][j] = cost[i + 1][j - 1];
      if (s[i - 1] != s[j - 1]) cost[i][j]++;
    }
  }
  int inf = 1e9;
  vector dp(k + 1, vector<int>(n + 1, inf));
  vector pre(k + 1, vector<int>(n + 1, 0));
  dp[0][0] = 0;
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= n; j++) {
      for (int p = 0; p < j; p++) {
        int c = dp[i - 1][p] + cost[p + 1][j];
        if (c < dp[i][j]) {
          dp[i][j] = c;
          pre[i][j] = p;
        }
      }
    }
  }

  int cnt = 0, c = inf;
  for (int i = 1; i <= k; i++) {
    if (dp[i][n] < c) {
      c = dp[i][n];
      cnt = i;
    }
  }
  cout << c << '\n';

  vector<string> rv;
  for (int cur = n; cnt; cnt--) {
    int lst = pre[cnt][cur];
    rv.emplace_back(s.substr(lst, cur - lst));
    cur = lst;
  }
  ranges::reverse(rv);

  string res;
  for (string &t: rv) {
    for (int l = 0, r = t.size() - 1; l < r; l++, r--) {
      if (t[l] != t[r]) {
        t[r] = t[l];
      }
    }
    if (!res.empty()) {
      res += '+';
    }
    res += t;
  }

  cout << res << '\n';
}
