#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int q;
  cin >> q;
  while (q--) {
    long long x, y, k;
    cin >> x >> y >> k;
    if (k < max(x, y)) {
      cout << -1 << endl;
      continue;
    }
    long long n = max(x, y), m = min(x, y);
    if ((n - m) % 2 == 1) cout << k - 1 << endl;
    else if ((k - n) % 2 == 1) cout << k - 2 << endl;
    else cout << k << endl;
  }
}
