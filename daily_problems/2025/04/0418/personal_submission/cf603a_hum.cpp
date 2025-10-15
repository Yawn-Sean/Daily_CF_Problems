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

  int n;
  string s;
  cin >> n >> s;
  int res{1}, cnt{};
  for (int i = 1; i < n; i++) {
    if (s[i] != s[i - 1]) {
      res++;
    } else {
      cnt++;
    }
  }
  cnt = min(cnt, 2);
  cout << res + cnt << '\n';
}
