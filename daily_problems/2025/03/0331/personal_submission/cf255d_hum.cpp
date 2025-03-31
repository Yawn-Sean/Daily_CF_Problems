#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  long long n, x, y, c;
  cin >> n >> x >> y >> c;

  long long l = 0, r = n * 2;

  while (l < r) {
    long long m = (l + r) / 2;
    long long res;

    res = 2 * m * m + 2 * m + 1;
    if (m > x - 1) res -= (m - (x - 1)) * (m - (x - 1));
    if (m > n - x) res -= (m - (n - x)) * (m - (n - x));
    if (m > y - 1) res -= (m - (y - 1)) * (m - (y - 1));
    if (m > n - y) res -= (m - (n - y)) * (m - (n - y));

    if (m > (x - 1) + (y - 1))
      res += (m - ((x - 1) + (y - 1)) - 1) * (m - ((x - 1) + (y - 1))) / 2;
    if (m > (x - 1) + (n - y))
      res += (m - ((x - 1) + (n - y)) - 1) * (m - ((x - 1) + (n - y))) / 2;
    if (m > (n - x) + (y - 1))
      res += (m - ((n - x) + (y - 1)) - 1) * (m - ((n - x) + (y - 1))) / 2;
    if (m > (n - x) + (n - y))
      res += (m - ((n - x) + (n - y)) - 1) * (m - ((n - x) + (n - y))) / 2;

    if (res >= c) {
      r = m;
    } else {
      l = m + 1;
    }
  }

  cout << l;
}
