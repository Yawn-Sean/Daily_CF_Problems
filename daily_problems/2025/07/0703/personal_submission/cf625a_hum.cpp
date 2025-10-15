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

  long long n, a, b, c;
  cin >> n >> a >> b >> c;
  long long res{};
  if (n >= b && b - c < a) {
    long long k = (n - b) / (b - c) + 1;
    res += k;
    n -= k * (b - c);
  }
  res += n / a;
  cout << res << '\n';
}
