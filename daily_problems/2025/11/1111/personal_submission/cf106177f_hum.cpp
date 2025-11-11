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

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    long long ans = 0;

    vector cnt(2, vector(2 * n + 5, 0));
    int cur = n + 2, msk = 0;

    while (n--) {
      cnt[msk][cur]++;

      int x;
      cin >> x;

      if (x & 1) msk ^= 1, cur--;
      else cur++;

      ans += cnt[msk][cur - 1] + cnt[msk ^ 1][cur + 1];
    }

    cout << ans << '\n';
  }
}
