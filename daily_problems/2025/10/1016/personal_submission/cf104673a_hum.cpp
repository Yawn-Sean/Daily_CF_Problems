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

  map<int, int> mp;
  int bound = 1e9;

  for (int i = 100000; i >= 0; i--) {
    long long val = 1;
    for (int j = 0; j <= i; j++) {
      if (val > bound) break;
      mp[val] = i + 1;
      val = val * (i - j) / (j + 1);
    }
  }

  int t;
  cin >> t;

  while (t--) {
    int x;
    cin >> x;
    auto pt = mp.find(x);

    if (pt != mp.end()) cout << pt->second << '\n';
    else cout << x + 1 << '\n';
  }

  return 0;
}
