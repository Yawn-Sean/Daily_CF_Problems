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
  vector<int> a(n), vis(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }
  int res{1};
  for (int i = 0; i < n; i++) {
    if (vis[i]) {
      continue;
    }
    int j = i;
    int cnt{};
    while (!vis[j]) {
      vis[j] = 1;
      j = a[j];
      cnt++;
    }
    if (j != i) {
      cout << -1 << endl;
      return 0;
    }
    if (cnt % 2 == 0) {
      cnt /= 2;
    }
    res = lcm(res, cnt);
  }
  cout << res;
}
