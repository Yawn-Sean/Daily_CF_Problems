#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define mod 1000000007 // 10^9 + 7
#define MOD 998244353  // 998244353

#define YES cout << "YES" << '\n'
#define NO cout << "NO" << '\n'
#define int long long
#define itn int

void solve() {
  int n;
  cin >> n;
  vector<int> t(n), w(n);
  int sum_t = 0;
  for (int i = 0; i < n; i++) {
    cin >> t[i] >> w[i];
    sum_t += t[i];
  }

  vector<int> dp(sum_t + 1, mod);
  dp[0] = 0;

  int cur_t = 0;
  for (int i = 0; i < n; i++) {

    int new_t = min(sum_t, cur_t + t[i]);

    for (int j = new_t; j >= t[i]; --j) {
      if (dp[j - t[i]] != mod) {
        dp[j] = min(dp[j], dp[j - t[i]] + w[i]);
      }
    }
    cur_t = new_t;
  }

  int ans = sum_t;
  for (int i = 0; i <= sum_t; ++i) {
    if (dp[i] != mod) {
      int cnt = dp[i];
      int cnt2 = sum_t - i;
      if (cnt <= cnt2) {
        ans = min(ans, cnt2);
      }
    }
  }
  cout << ans << '\n';
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt;
  // cin >> tt;
  tt = 1;
  while (tt--) {
    solve();
  }
  return 0;
}