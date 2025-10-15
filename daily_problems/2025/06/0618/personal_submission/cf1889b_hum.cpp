#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void solve() {
  int n;
  long long c;
  cin >> n >> c;
  vector<long long> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> idx(n - 1);
  ranges::iota(idx, 1);
  ranges::sort(idx, [&](int i, int j) {
    return i * c - a[i] < j * c - a[j];
  });
  long long cur = a[0];
  for (int i = 0; i < n - 1; ++i) {
    if (cur + a[idx[i]] >= (idx[i] + 1) * c) {
      cur += a[idx[i]];
    } else {
      cout << "No" << endl;
      return;
    }
  }
  cout << "Yes" << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
