#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<array<int, 5>> dp(n);
  vector<array<int, 5>> pre(n);
  for (int i = 0; i < 5; i++) {
    dp[0][i] = 1;
  }

  for (int i = 1; i < n; i++) {
    for (int p = 0; p < 5; p++) {
      if (dp[i - 1][p]) {
        for (int k = 0; k < 5; k++) {
          if (a[i] > a[i - 1] && k > p) {
            dp[i][k] = 1;
            pre[i][k] = p;
          }
          if (a[i] < a[i - 1] && k < p) {
            dp[i][k] = 1;
            pre[i][k] = p;
          }
          if (a[i] == a[i - 1] && k != p) {
            dp[i][k] = 1;
            pre[i][k] = p;
          }
        }
      }
    }
  }
  vector<int> res;
  for (int i = 0; i < 5; i++) {
    if (dp[n - 1][i]) {
      res.push_back(i + 1);
      break;
    }
  }
  if (res.empty()) {
    cout << -1 << endl;
  } else {
    for (int i = n - 1; i > 0; i--) {
      int p = res.back() - 1;
      res.push_back(pre[i][p] + 1);
    }
    ranges::reverse(res);
    for (int e: res) {
      cout << e << " ";
    }
    cout << endl;
  }
}
