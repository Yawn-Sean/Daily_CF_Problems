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
  string s;
  cin >> s;
  string t;

  for (int i = 0; i < n; i++) {
    if (i % 2) {
      t += '0';
    } else {
      t += '1';
    }
  }
  int res{};
  for (int i = 0; i < n; i++) {
    if (s[i] != t[i]) {
      res++;
    }
  }
  cout << min(res, n - res) << endl;
}
