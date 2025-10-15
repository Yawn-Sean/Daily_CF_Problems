#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  vector ds{119, 18, 93, 91, 58, 107, 111, 82, 127, 123};
  int n, k;
  cin >> n >> k;
  vector<int> strs(n);
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < s.size(); ++j) {
      strs[i] |= (s[j] - '0') << (6 - j);
    }
  }
  vector dp(n + 1, vector(k + 1, 0));
  dp[n][0] = 1;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j <= k; ++j) {
      if (dp[i + 1][j]) {
        for (int d = 0; d < 10; ++d) {
          if ((strs[i] & ds[d]) == strs[i]) {
            int nj = __popcount(ds[d] ^ strs[i]);
            if (j + nj <= k) {
              dp[i][j + nj] = 1;
            }
          }
        }
      }
    }
  }

  if (dp[0][k] == 0) {
    cout << -1 << endl;
  } else {
    int cur = k;
    for (int i = 0; i < n; ++i) {
      for (int j = 9; j >= 0; j--) {
        if ((strs[i] & ds[j]) == strs[i]) {
          int nj = __popcount(ds[j] ^ strs[i]);
          if (cur >= nj && dp[i + 1][cur - nj]) {
            cout << j;
            cur -= nj;
            break;
          }
        }
      }
    }
  }
}
