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
  cin >> n;

  string s1, s2;
  cin >> s1 >> s2;

  int res{};

  for (int i = 0; i < n / 2; i++) {
    char a = s1[i], b = s1[n - 1 - i], c = s2[i], d = s2[n - 1 - i];
    if ((a == b && c == d) || (a == c && b == d) || (a == d && b == c))
      res += 0;
    else if (a == c || a == d || b == c || b == d || c == d)
      res += 1;
    else
      res += 2;
  }

  if (n & 1) {
    res += s1[n / 2] != s2[n / 2];
  }

  cout << res;
}
