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

  int n, x;
  cin >> n >> x;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  ranges::sort(a, greater{});
  ranges::sort(b);
  int j{};
  int res{};
  for (int i = 0; i < n; i++) {
    while (j < n && a[i] + b[j] < x) {
      j++;
    }
    if (j == n) {
      cout << 1 << " " << res << '\n';
      return 0;
    }
    res++;
    j++;
  }
  cout << 1 << " " << res << '\n';
}
