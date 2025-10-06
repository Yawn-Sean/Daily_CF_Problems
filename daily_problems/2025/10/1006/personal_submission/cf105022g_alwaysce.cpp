#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 MOD = 998244353;

inline i64 norm(i64 x) {
  x %= MOD;
  if (x < 0) x += MOD;
  return x;
}

i64 mod_pow(i64 base, i64 exp) {
  i64 res = 1;
  while (exp) {
    if (exp % 2) res = res * base % MOD;
    base = base * base % MOD;
    exp /= 2;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  i64 n, k;
  cin >> n >> k;

  // rank(A) = 1
  // a(ba)(ba)...(ba)b^T
  // tr(A)^(k-1) * A
  vector<i64> a(n), b(n);
  for (i64 i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (i64 i = 0; i < n; i++) {
    cin >> b[i];
  }

  i64 sumA = 0, sumB = 0, s = 0;
  for (i64 i = 0; i < n; i++) {
    sumA += norm(a[i]);
    sumB += norm(b[i]);
    s += norm(a[i] * b[i]);
  }

  sumA = norm(sumA);
  sumB = norm(sumB);
  s = norm(s);

  i64 ans;
  if (k == 0) {
    ans = norm(n);
  } else {
    ans = mod_pow(s, k - 1) % MOD;
    ans = ans * sumA % MOD;
    ans = ans * sumB % MOD;
  }
  cout << ans % MOD;
  return 0;
}
