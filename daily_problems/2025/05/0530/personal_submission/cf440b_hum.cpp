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
  vector<long long> a(n);
  long long sum{};
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  long long x = sum / n;
  long long res{};
  for (int i = 0; i < n; i++) {
    if (a[i] > x) {
      res += a[i] - x;
      a[i + 1] += a[i] - x;
    } else if (a[i] < x) {
      res += x - a[i];
      a[i + 1] += a[i] - x;
    }
  }
  cout << res << '\n';
}
