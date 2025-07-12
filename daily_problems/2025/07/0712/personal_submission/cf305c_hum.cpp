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
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  map<long long, int> mp;
  for (int i = 0; i < n; i++) {
    mp[a[i]]++;
    long long u = a[i];
    while (mp[u] >= 2) {
      mp[u] -= 2;
      mp[u + 1]++;
      u++;
    }
  }
  int cnt{};
  long long m{};
  for (auto [k, v]: mp) {
    if (v != 0) {
      cnt++;
    }
    m = max(m, k);
  }
  cout << m - cnt + 1 << '\n';
}
