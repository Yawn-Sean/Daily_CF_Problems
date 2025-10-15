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
  cin >> n >> m;
  vector<int> a(n), cnt(m + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  ranges::sort(a);
  int k = ranges::max(cnt);
  cout << min(n, 2 * n - 2 * k) << endl;

  for (int i = 0; i < n; i++) {
    cout << a[i] << " " << a[(i + k) % n] << endl;
  }
}
