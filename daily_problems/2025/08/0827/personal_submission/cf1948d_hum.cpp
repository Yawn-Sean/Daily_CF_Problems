#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif


void solve() {
  string s;
  cin >> s;
  int n = s.size();
  int res{};
  vector lcp(n + 1, vector(n + 1, 0));
  auto check = [&](char a, char b) {
    return a == b || a == '?' || b == '?';
  };

  for (int i = n - 1; i >= 0; i--) {
    for (int j = n - 1; j > i; j--) {
      if (check(s[i], s[j])) {
        lcp[i][j] = lcp[i + 1][j + 1] + 1;
      } else {
        lcp[i][j] = 0;
      }
      if (lcp[i][j] >= j - i) {
        res = max(res, j - i);
      }
    }
  }
  cout << res * 2 << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
