#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 MOD = 1000000007;

i64 mod_pow(i64 a, i64 e) {
  i64 r = 1 % MOD;
  while (e) {
    if (e & 1) r = (r * a) % MOD;
    a = (a * a) % MOD;
    e >>= 1;
  }
  return r;
}
i64 mod_inv(i64 x) { return mod_pow(x, MOD - 2); }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    i64 sumA = 0;
    for (int i = 0; i < n; i++) {
      i64 x;
      cin >> x;
      x %= MOD;
      sumA += x;
      if (sumA >= MOD) sumA -= MOD;
    }

    i64 time = 0;
    for (int i = 0; i < n; i++) {
      time += n / gcd(i, n);
      if (time >= MOD) time -= MOD;
    }

    i64 inv_n = mod_inv(n % MOD);
    i64 ans = sumA * time % MOD;
    ans = ans * inv_n % MOD;
    ans = ans * inv_n % MOD;

    cout << ans << '\n';
  }

  return 0;
}
