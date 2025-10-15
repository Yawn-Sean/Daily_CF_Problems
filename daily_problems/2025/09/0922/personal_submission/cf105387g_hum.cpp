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

  auto add = [&](int &x, int y) -> void {
    x += y;
    if (x >= mod) x -= mod;
  };

  auto minus = [&](int &x, int y) -> void {
    x -= y;
    if (x < 0) x += mod;
  };

  int n, kr, kg, kb;
  cin >> n >> kr >> kg >> kb;

  vector<int> dpr(n + 1, 0), dpg(n + 1, 0), dpb(n + 1, 0);

  dpr[1] = 1, dpg[1] = 1, dpb[1] = 1;

  for (int i = 2; i <= n; i++) {
    int total = 0;
    add(total, dpr[i - 1]);
    add(total, dpg[i - 1]);
    add(total, dpb[i - 1]);

    dpr[i] = total;
    if (i > kr + 1) {
      minus(dpr[i], dpg[i - kr - 1]);
      minus(dpr[i], dpb[i - kr - 1]);
    } else if (i == kr + 1) minus(dpr[i], 1);

    dpg[i] = total;
    if (i > kg + 1) {
      minus(dpg[i], dpr[i - kg - 1]);
      minus(dpg[i], dpb[i - kg - 1]);
    } else if (i == kg + 1) minus(dpg[i], 1);

    dpb[i] = total;
    if (i > kb + 1) {
      minus(dpb[i], dpr[i - kb - 1]);
      minus(dpb[i], dpg[i - kb - 1]);
    } else if (i == kb + 1) minus(dpb[i], 1);
  }

  int ans = 0;
  add(ans, dpr[n]);
  add(ans, dpg[n]);
  add(ans, dpb[n]);

  cout << ans;
}
