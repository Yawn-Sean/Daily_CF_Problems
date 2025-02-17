#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  long double n, p;
  cin >> n >> p;
  vector<array<long double, 2>> a(n);
  long double s{};
  for (int i = 0; i < n; ++i) {
    cin >> a[i][0] >> a[i][1];
    s += a[i][0];
  }
  if (s <= p) {
    cout << -1 << endl;
    return 0;
  }

  long double l{0}, r{1e12};
  for (int i = 0; i < 500; ++i) {
    long double mid = (l + r) / 2;
    long double need = 0;
    for (int j = 0; j < n; ++j) {
      need += max(0.0L, mid - a[j][1] / a[j][0]) * a[j][0];
    }
    if (need > p * mid) {
      r = mid;
    } else {
      l = mid;
    }
  }
  cout << setprecision(10) << l << endl;
}
