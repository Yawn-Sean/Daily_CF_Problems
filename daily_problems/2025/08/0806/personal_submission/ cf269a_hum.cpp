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
  int res{};
  for (int i = 0; i < n; i++) {
    int k, a;
    cin >> k >> a;
    res = max(res, k + 1);
    while (a > 1) {
      a = (a + 3) / 4;
      k++;
    }

    res = max(res, k);
  }
  cout << res << '\n';
}

