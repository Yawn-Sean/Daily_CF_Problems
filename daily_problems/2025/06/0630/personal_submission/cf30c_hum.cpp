#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

struct Nod {
  int x, y, t;
  double p;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<Nod> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].x >> a[i].y >> a[i].t >> a[i].p;
  }
  ranges::sort(a, [](Nod &a, Nod &b) {
    return a.t < b.t;
  });

  auto check = [](Nod &a, Nod &b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    long long d = 1LL * dx * dx + 1LL * dy * dy;
    return d <= 1ll * (a.t - b.t) * (a.t - b.t);
  };

  vector<double> dp(n);
  dp[0] = a[0].p;
  for (int i = 1; i < n; i++) {
    dp[i] = a[i].p;
    for (int j = 0; j < i; j++) {
      if (check(a[i], a[j])) {
        dp[i] = max(dp[i], dp[j] + a[i].p);
      }
    }
  }
  cout << fixed << setprecision(10) << ranges::max(dp) << '\n';
}
