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

  int n, m;
  std::cin >> n >> m;
  std::vector<int> s(n), l(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> l[i];
  }

  matrix<Z> a(n, n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      a[i][j] += s[i] * s[j] + s[i] * l[j] + s[j] * l[i];
    }
  }
  a ^= m;
  Z ans = 0;
  for (int i = 0; i < n; i++) ans += a[i][0];
  std::cout << ans << "\n";
}
