#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

int mod = 1e9 + 7;

long long power(long long a, long long b) {
  long long y = 1;
  for (; b; b >>= 1) {
    if (b & 1) y = y * a % mod;
    a = a * a % mod;
  }
  return y;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    int total = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      total += x;
      if (total >= mod) total -= mod;
    }

    int times = 0;
    for (int i = 0; i < n; i++) {
      times += n / gcd(i, n);
      if (times >= mod) times -= mod;
    }

    int revn = power(n, mod - 2);
    cout << 1ll * total * times % mod * revn % mod * revn % mod << '\n';
  }
}
