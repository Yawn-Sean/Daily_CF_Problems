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

  int n;
  cin >> n;
  vector<vector<int>> a(n);
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    while (k--) {
      int x;
      cin >> x;
      a[i].push_back(x);
    }
    ranges::sort(a[i]);
  }
  auto count = [&](vector<int> &ar, int l, int r) -> long long {
    return ranges::lower_bound(ar, r) - ranges::lower_bound(ar, l);
  };
  int res{};
  for (int i = 0; i < n; i++) {
    for (int j = 1; j < a[i].size(); j++) {
      long long l = count(a[(i + 1) % n], a[i][j - 1], a[i][j]);
      long long r = count(a[(i - 1 + n) % n], a[i][j - 1], a[i][j]);
      res += l != r;
    }
  }
  cout << res << endl;
}
