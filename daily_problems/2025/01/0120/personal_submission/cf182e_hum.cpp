#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, l;
  cin >> n >> l;
  vector<array<int, 3>> a;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    a.push_back({x, y, i});
    if (x != y) {
      a.push_back({y, x, i});
    }
  }
  n = a.size();
  vector dp(l + 1, vector<long long>(n));
  for (int i = 0; i < n; i++) {
    if (a[i][0] > l) {
      continue;
    }
    dp[a[i][0]][i] = 1;
  }
  int mod = 1e9 + 7;
  for (int i = 0; i <= l; i++) {
    for (int cur = 0; cur < n; cur++) {
      for (int pre = 0; pre < n; pre++) {
        if (a[cur][2] == a[pre][2]) {
          continue;
        }
        if (i - a[cur][0] >= 0 && a[cur][1] == a[pre][0]) {
          dp[i][cur] += dp[i - a[cur][0]][pre];
          dp[i][cur] %= mod;
        }
      }
    }
  }
  long long res = 0;
  for (int i = 0; i < n; i++) {
    res = (res + dp[l][i]) % mod;
  }
  cout << res << '\n';
}
