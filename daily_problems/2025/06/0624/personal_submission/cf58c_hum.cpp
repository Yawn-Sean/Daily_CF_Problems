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
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i < n / 2) {
      mp[a[i] - i]++;
    } else {
      mp[a[i] - (n - 1 - i)]++;
    }
  }
  int m{};
  for (auto [k, cnt]: mp) {
    if (k <= 0) {
      continue;
    }
    m = max(m, cnt);
  }
  cout << n - m << '\n';
}
