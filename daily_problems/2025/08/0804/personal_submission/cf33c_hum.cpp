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
  int sum{};
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  int t{}, cur{};
  for (int i = 0; i < n; i++) {
    if (cur + a[i] < 0) {
      cur = 0;
    } else {
      cur += a[i];
      t = max(t, cur);
    }
  }
  t = max(t, cur);
  cout << t * 2 - sum << endl;
}
