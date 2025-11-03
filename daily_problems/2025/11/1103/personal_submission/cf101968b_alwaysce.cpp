#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1000000007;

i64 fac[500050];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  fac[0] = 1;
  for (int i = 1; i <= 500000; i++) {
    fac[i] = (fac[i - 1] * i) % mod;
  }

  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    int n;
    cin >> n;
    vector<int> xs(2 * n), ys(2 * n);

    vector<int> xl, yl;
    for (int i = 0; i < 2 * n; i++) {
      cin >> xs[i] >> ys[i];
      xl.push_back(xs[i]);
      yl.push_back(ys[i]);
    }

    sort(xl.begin(), xl.end());
    sort(yl.begin(), yl.end());
    int x1 = xl[n - 1], x2 = xl[n];
    int y1 = yl[n - 1], y2 = yl[n];

    vector<int> cnt(4);
    auto get_type = [&](int x, int y) {
      if (x <= x1 && y <= y1) {
        return 0;
      } else if (x >= x2 && y <= y1) {
        return 1;
      } else if (x <= x1 && y >= y2) {
        return 2;
      } else if (x >= x2 && y >= y2) {
        return 3;
      }
    };

    for (int i = 0; i < 2 * n; i++) {
      int t = get_type(xs[i], ys[i]);
      cnt[t]++;
    }

    i64 ans = 1ll;
    for (int tp = 0; tp < 2; tp++) {
      if (cnt[tp] != cnt[3 - tp]) {
        ans = 0;
        break;
      }
      ans *= fac[cnt[tp]] % mod;
      ans %= mod;
    }
    cout << ans % mod << "\n";
  }
  return 0;
}
