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

  long long n;
  cin >> n;
  int res{};
  for (long long i = 1; (3 * i + 1) * i / 2 <= n; i++) {
    if ((n - (3 * i + 1) * i / 2) % 3 == 0) {
      res++;
    }
  }
  cout << res << endl;
}
