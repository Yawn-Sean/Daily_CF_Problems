#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> t(n + 1);
  t[0] = -1500;
  for (int i = 0; i < n; i++)
    cin >> t[i + 1];
  int inf = 1e9;
  vector dp(n + 1, inf);
  dp[0] = 0;
  vector<int> res;
  for (int i = 1; i <= n; i++) {
    dp[i] = min(dp[i], dp[i - 1] + 20);
    int j = upper_bound(t.begin(), t.begin() + i, t[i] - 90) - t.begin();
    dp[i] = min(dp[i], dp[j - 1] + 50);
    j = upper_bound(t.begin(), t.begin() + i, t[i] - 1440) - t.begin();
    dp[i] = min(dp[i], dp[j - 1] + 120);

    res.push_back(dp[i] - dp[i - 1]);
  }
  for (int i = 0; i < n; i++)
    cout << res[i] << endl;
}
