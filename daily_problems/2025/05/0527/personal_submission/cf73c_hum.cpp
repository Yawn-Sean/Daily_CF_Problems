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
  int k, n;
  cin >> s >> k >> n;
  vector c(26, vector(26, 0));
  for (int i = 0; i < n; i++) {
    char u, v;
    int x;
    cin >> u >> v >> x;
    c[u - 'a'][v - 'a'] = x;
  }
  n = s.size();

  if (k == 0) {
    int res{};
    for (int i = 0; i < n - 1; i++) {
      res += c[s[i] - 'a'][s[i + 1] - 'a'];
    }
    cout << res << endl;
    return 0;
  }

  int inf = 1e9;
  vector dp(n, vector(k + 1, vector(26, -inf)));
  for (int i = 0; i < 26; i++) {
    if (s[0] - 'a' != i) {
      dp[0][1][i] = 0;
    } else {
      dp[0][0][s[0] - 'a'] = 0;
    }
  }

  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= k; j++) {
      for (int x = 0; x < 26; x++) {
        int t{1};
        if (x == s[i] - 'a') {
          t = 0;
        }
        for (int y = 0; y < 26; y++) {
          if (j + t <= k) {
            dp[i][j + t][x] = max(dp[i][j + t][x], dp[i - 1][j][y] + c[y][x]);
          }
        }
      }
    }
  }
  int res{-inf};
  for (int i = 0; i <= k; i++) {
    for (int j = 0; j < 26; j++) {
      res = max(res, dp[n - 1][i][j]);
    }
  }
  cout << res << endl;
}
