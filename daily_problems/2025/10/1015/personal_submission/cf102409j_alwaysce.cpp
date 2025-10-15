#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1000000007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  i64 l;
  cin >> n >> l;

  vector<i64> xs(n + 1);
  for (int i = 1; i <= n - 1; i++) {
    cin >> xs[i];
  }

  /*
    [0] [i] [j] [j] [L]
    枚举中间的这个j 然后左右两边分别找一个点

    从[0, j]寻找i
    满足

    |(xs[i] - 0) - (xs[j] - xs[i])|最小
    -> |2*xs[i] - xs[j]| 最小
  */

  xs[0] = 0;
  xs[n] = l;

  i64 ans = l;
  int il = 1, ir = 3;
  for (int j = 2; j <= n - 2; j++) {
    while (il + 1 < j &&
           llabs(2ll * xs[il + 1] - xs[j]) <= llabs(2 * xs[il] - xs[j])) {
      ++il;
    }

    if (ir < j + 1) {
      ir = j + 1;
    }

    while (ir + 1 <= n - 1 && llabs(2ll * xs[ir + 1] - (l + xs[j])) <=
                                  llabs(2ll * xs[ir] - (l + xs[j]))) {
      ++ir;
    }

    i64 a = xs[il];
    i64 b = xs[j] - xs[il];
    i64 c = xs[ir] - xs[j];
    i64 d = l - xs[ir];

    i64 mx = max({a, b, c, d});
    i64 mi = min({a, b, c, d});
    ans = min(ans, mx - mi);
  }

  cout << ans << endl;
  return 0;
}
