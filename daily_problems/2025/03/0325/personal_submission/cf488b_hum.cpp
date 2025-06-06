#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  ranges::sort(a);

  if (n == 0) {
    cout << "YES\n";
    cout << "1\n";
    cout << "1\n";
    cout << "3\n";
    cout << "3\n";
    return 0;
  }
  if (n == 1) {
    cout << "YES\n";
    cout << 2 * a[0] << "\n";
    cout << 2 * a[0] << "\n";
    cout << 3 * a[0] << "\n";
    return 0;
  }

  if (a.back() > a[0] * 3) {
    cout << "NO\n";
    return 0;
  }
  if (n == 2) {
    cout << "YES\n";
    cout << 3 * a[0] << "\n";
    cout << 4 * a[0] - a[1] << "\n";
    return 0;
  }
  if (n == 3) {
    if (a[2] == 3 * a[0]) {
      cout << "YES\n";
      cout << 4 * a[0] - a[1] << "\n";
    } else if (a[1] + a[2] == 4 * a[0]) {
      cout << "YES\n";
      cout << 3 * a[0] << "\n";
    } else if (a[2] % 3 == 0 && a[0] + a[1] == a[2] / 3 * 4) {
      cout << "YES\n";
      cout << a[2] / 3 << "\n";
    } else {
      cout << "NO\n";
    }
    return 0;
  }
  if (a[3] == a[0] * 3 && a[1] + a[2] == 4 * a[0]) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
  return 0;
}
