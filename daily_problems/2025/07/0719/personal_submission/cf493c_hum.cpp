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
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int m;
  cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  ranges::sort(b);
  a.push_back(max(a[n - 1], b[m - 1]) + 1);

  ranges::sort(a);
  // a.erase(ranges::unique(a).begin(), a.end());
  int sa{n * 3}, sb{m * 3};
  int diff{sa - sb};
  for (int i = 0; i < a.size(); i++) {
    int ca = i * 2 + (a.size() - i - 1) * 3;
    int p = ranges::lower_bound(b, a[i]) - b.begin();

    int cb = p * 2 + (m - p) * 3;
    if (ca - cb > diff) {
      sa = ca;
      sb = cb;
      diff = sa - sb;
    }
  }

  cout << sa << ':' << sb << '\n';
}
