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

  int mod = 1e9 + 7;
  int n;
  cin >> n;

  int cur = 0, pos = 0, ans = 1;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    if (x > cur) {
      ans = 1ll * ans * (i - pos + 1) % mod;
      cur = x;
      pos = i;
    }
  }

  cout << ans;
}
