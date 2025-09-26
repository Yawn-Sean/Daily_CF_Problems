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
    int n, x, y;
    cin >> n >> x >> y;

    vector<long long> a(n + 2);
    for (int i = 1; i <= n; i++) cin >> a[i];
    long long sum = 0;
    for (int i = 1; i <= n; i++) sum += a[i];

    long long mx1 = -1e15, mx2 = -1e15;
    int idx = -1;
    for (int i = 1; i <= n; i++) {
      long long bj = (a[i] & y) - a[i];
      if (bj > mx1) {
        mx2 = mx1;
        mx1 = bj;
        idx = i;
      } else if (bj > mx2) mx2 = bj;
    }

    long long mx_d = 1e15;

    for (int i = 1; i <= n; i++) {
      long long ci = (a[i] | x) - a[i];
      long long di = ((a[i] | x) & y) - a[i];
      long long t = (i != idx ? mx1 : mx2);
      long long cur = max(di, ci + t);
      mx_d = min(mx_d, cur);
    }
    cout << sum + mx_d << "\n";
  }
}
