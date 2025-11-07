#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1e9 + 7;

i64 mod_str(string& s) {
  i64 res = 0;
  for (char c : s) {
    res = (res * 10 + (c - '0')) % mod;
  }
  return res % mod;
}

i64 qpow(i64 a, i64 b) {
  i64 res = 1;
  a %= mod;
  while (b > 0) {
    if (b & 1) {
      res = res * a % mod;
    }
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string x, op, y;
  cin >> x >> op >> y;
  if (op[0] == '+') {
    i64 xm = mod_str(x);
    i64 ym = mod_str(y);
    cout << (xm + ym) % mod << '\n';
  } else if (op[0] == '-') {
    i64 xm = mod_str(x);
    i64 ym = mod_str(y);
    cout << (xm - ym + mod) % mod << '\n';
  } else if (op[0] == '*') {
    i64 xm = mod_str(x);
    i64 ym = mod_str(y);
    cout << (xm * ym) % mod << '\n';
  } else if (op[0] == '^') {
    i64 xm = mod_str(x);
    auto calc = [&](i64 a, string b) {
      i64 res = 1;
      a %= mod;
      for (char c : b) {
        res = qpow(res, 10) * qpow(a, c - '0') % mod;
      }
      return res;
    };

    cout << calc(xm, y) % mod << '\n';
  }

  return 0;
}
