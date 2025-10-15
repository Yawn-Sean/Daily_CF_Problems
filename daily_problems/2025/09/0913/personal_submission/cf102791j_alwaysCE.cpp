#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
For each i , which character should we pair it with?
*/

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  string s;
  cin >> s;

  /*
    dp[i] = max(dp[j] + 1),
    对于所有的下标j满足 s[j+1] == s[i] 且 j + 1 <= i - 1

  */
  int inf = 1e9;
  vector<int> dp(n + 1, -inf);
  vector<int> nxt(n, -1);
  dp[n] = 0;

  vector<int> mx(26, -inf), idx(26, -1);
  for (int i = n - 1; i >= 0; i--) {
    int c = s[i] - 'a';
    if (mx[c] != -inf) {
      dp[i] = 1 + mx[c];
      nxt[i] = idx[c];
    } else {
      dp[i] = -inf;
      nxt[i] = -1;
    }

    if (dp[i + 1] > mx[c]) {
      mx[c] = dp[i + 1];
      idx[c] = i;
    }
  }

  if (dp[0] < 0) {
    cout << -1 << "\n";
    return 0;
  }

  int ans = dp[0];
  cout << ans << "\n";
  vector<int> res;
  for (int i = 0; i < n;) {
    int j = nxt[i];
    res.push_back(j - i + 1);
    i = j + 1;
  }
  for (auto x : res) {
    cout << x << " ";
  }
  cout << "\n";

  return 0;
}
