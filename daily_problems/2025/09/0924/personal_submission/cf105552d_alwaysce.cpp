#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 998244353;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  i64 n, r;
  cin >> n >> r;

  const long double PI = acosl(-1.0L);
  vector<long double> a(n), b(n), c(n);
  for (i64 i = 0; i < n; i++) {
    cin >> a[i] >> b[i] >> c[i];
  }
  long double ans = 0.0L;
  // Ax + By + C = 0
  // 把单位圆切成了两个部分
  // 找出两段面积的比例是多少
  for (int i = 0; i < n; i++) {
    long double A = a[i], B = b[i], C = c[i];
    long double norm = hypotl(A, B);

    long double d = fabsl(C) / norm;
    long double R = (long double)r;

    long double theta = 2.0 * acosl(d / R);
    long double S_small = R * R * acosl(d / R) - d * sqrtl(R * R - d * d);
    long double S_large = R * R * PI - S_small;

    long double ratio = S_small / S_large;
    ans = max(ans, ratio);
  }

  cout << fixed << setprecision(10) << ans / (ans + 1) << " "
       << (long double)1.0 / (ans + 1) << "\n";

  return 0;
}
