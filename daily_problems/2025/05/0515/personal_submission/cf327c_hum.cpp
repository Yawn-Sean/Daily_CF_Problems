#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

int mod = 1e9 + 7;

long long qp(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  int k;
  cin >> s >> k;
  int v{1}, res{};
  for (char c: s) {
    if (c == '0' || c == '5') {
      res = (res + v) % mod;
    }
    v = v * 2 % mod;
  }


  cout << 1ll * res * (qp(2, 1ll * k * s.size()) - 1) % mod * qp(qp(2, s.size()) - 1, mod - 2) % mod;

  return 0;
}
