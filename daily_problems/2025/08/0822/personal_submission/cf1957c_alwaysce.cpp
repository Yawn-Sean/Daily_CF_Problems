#include <cstdint>
#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::ios_base;
using std::vector;
using i64 = int64_t;

int MX = 300000;
i64 mod = 1000000007;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  vector<i64> dp(MX + 1);
  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 3;
  for (int i = 3; i <= MX; ++i) {
    dp[i] = dp[i - 1] % mod;
    dp[i] = (dp[i] + 2ll * (i - 1) % mod * dp[i - 2] % mod) % mod;
  }

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> used(n + 1, 0);
    for (int j = 0; j < k; j++) {
      int r, c;
      cin >> r >> c;
      used[r] = 1;
      used[c] = 1;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      if (!used[i]) {
        ++cnt;
      }
    }
    cout << dp[cnt] % mod << endl;
  }
  return 0;
}
