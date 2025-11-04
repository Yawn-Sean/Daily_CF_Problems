#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 998244353;

i64 pow(i64 a, i64 b, i64 m) {
  i64 res = 1;
  a %= m;
  while (b > 0) {
    if (b & 1) {
      res = res * a % m;
    }
    a = a * a % m;
    b >>= 1;
  }
  return res;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int MX = 1e6;
  vector<i64> ans(MX + 1);

  // 偶数答案会 xor C(n/2,n) 还有 C(n,n)
  // 奇数答案会 xor C(n,n)
  vector<i64> fact(MX + 1, 1), inv_fact(MX + 1, 1);
  for (int i = 1; i <= MX; i++) {
    fact[i] = fact[i - 1] * i % mod;
  }
  inv_fact[MX] = pow(fact[MX], mod - 2, mod);
  for (int i = MX - 1; i >= 0; i--) {
    inv_fact[i] = inv_fact[i + 1] * (i + 1) % mod;
  }

  auto comb = [&](int n, int k) -> i64 {
    if (k < 0 || k > n) {
      return 0;
    }
    return fact[n] * inv_fact[k] % mod * inv_fact[n - k] % mod;
  };

  for (int i = 1; i <= MX; i++) {
    ans[i] = ans[i - 1] ^ 1;
    if (i % 2 == 0) {
      ans[i] ^= comb(i, i / 2);
    }
  }

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << ans[n] << '\n';
  }
  return 0;
}
