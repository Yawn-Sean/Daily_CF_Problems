#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 998244353;
const int MX = 2000000;
i64 f[MX + 5], P[MX + 5], S[MX + 5];
i64 invS[MX + 5];

i64 qpow(i64 base, i64 exp) {
  i64 ans = 1;
  base %= mod;
  while (exp) {
    if (exp & 1) {
      ans = ans * base % mod;
    }
    base = base * base % mod;
    exp >>= 1;
  }
  return ans;
}

i64 inv(i64 x) { return qpow(x, mod - 2); }

void init() {
  f[1] = 1;
  i64 pre = 1;
  i64 sum = 0;

  P[1] = 1;
  for (int i = 2; i <= MX; i++) {
    S[i] = (1ll * i * (i + 1) / 2 - 1) % mod;
    P[i] = P[i - 1] * S[i] % mod;
  }

  i64 invP = inv(P[MX]);
  for (int i = MX; i >= 2; i--) {
    invS[i] = invP * P[i - 1] % mod;
    invP = invP * S[i] % mod;
  }

  for (int i = 2; i <= MX; i++) {
    i64 S = (1ll * i * (i + 1) / 2 - 1) % mod;

    sum = (sum + pre + f[i - 1]) % mod;

    f[i] = (1ll + sum * invS[i] % mod) % mod;

    pre = (pre + f[i]) % mod;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  init();

  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    int len = r - l + 1;
    i64 center = (l + r) * inv(2) % mod;
    cout << (f[len] * center % mod) << '\n';
  }

  return 0;
}
