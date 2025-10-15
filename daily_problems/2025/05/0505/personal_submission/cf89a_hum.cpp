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

  long long n, m, k;
  cin >> n >> m >> k;
  vector<long long> a(n);
  long long mi{INT_MAX};
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i % 2 == 0) {
      mi = min(mi, a[i]);
    }
  }
  if (n % 2 == 0) {
    cout << "0" << endl;
    return 0;
  }
  cout << min(m / (n / 2 + 1) * k, mi) << endl;
}
