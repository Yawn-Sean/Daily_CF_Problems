#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  long long n;
  cin >> n;
  vector<array<int, 2>> ps(n);
  for (int i = 0; i < n; i++) {
    cin >> ps[i][0] >> ps[i][1];
  }

  long long res = n * (n - 1) * (n - 2) / 6;
  for (int i = 0; i < n; i++) {
    map<array<int, 2>, int> mp;
    for (int j = i + 1; j < n; j++) {
      int x = ps[i][0] - ps[j][0];
      int y = ps[i][1] - ps[j][1];
      int g = gcd(x, y);
      x /= g;
      y /= g;
      if (x < 0 || (x == 0 && y < 0)) {
        x = -x;
        y = -y;
      }
      res -= mp[{x, y}];
      mp[{x, y}]++;
    }
  }
  cout << res << endl;
}
