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

  long long n, k;
  cin >> n >> k;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  ranges::sort(a);
  int res{};
  for (int i = 0; i < n; i++) {
    if (a[i] <= 2 * k) {
      k = max(k, a[i]);
    } else {
      k = 2 * k;
      res++;
      i--;
    }
  }
  cout << res << endl;
}
