#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1000000007;

const long double PI = acosl(-1.0L);
inline long double area_int(i64 n, long double m, long double T) {
  if (n < 3.0L) return 0.0L;
  long double L = T - m * n;
  if (L <= 0.0L) return 0.0L;
  long double cotv = 1.0L / tanl(PI / n);
  return (L * L) / (4.0L * n) * cotv;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    i64 m_in, T_in;
    cin >> m_in >> T_in;

    i64 n_max_int = T_in / m_in;
    i64 l = 3, r = n_max_int;

    while (l < r) {
      i64 mid = (l + r) / 2;
      if (area_int(mid, (long double)m_in, (long double)T_in) <
          area_int(mid + 1, (long double)m_in, (long double)T_in)) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }

    cout << fixed << setprecision(12)
         << area_int(l, (long double)m_in, (long double)T_in) << "\n";
  }
  return 0;
}
