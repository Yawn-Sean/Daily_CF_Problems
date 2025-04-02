#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> a(26);
  for (int i = 0; i < 26; i++) {
    cin >> a[i];
  }
  int mod = 1e9 + 7;

  vector<array<int, 2>> dp(n + 1);

  dp[0][0] = 1;
  int inf = 1e9;
  for (int i = 1; i <= n; i++) {
    dp[i][1] = inf;
  }
  int res = 1;
  for (int i = 1; i <= n; i++) {
    int len = inf;
    for (int j = i; j > 0; j--) {
      len = min(len, a[s[j - 1] - 'a']);
      if (i - j + 1 > len) {
        break;
      }
      dp[i][0] = (dp[i][0] + dp[j - 1][0]) % mod;
      dp[i][1] = min(dp[i][1], dp[j - 1][1] + 1);
      res = max(res, i - j + 1);
    }
  }
  cout << dp[n][0] << endl;
  cout << res << endl;
  cout << dp[n][1] << endl;
}
