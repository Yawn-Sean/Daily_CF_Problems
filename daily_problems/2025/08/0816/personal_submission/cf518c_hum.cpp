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

  int n, m, k;
  cin >> n >> m >> k;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<int> pos(n + 1);
  for (int i = 0; i < n; i++)
    pos[a[i]] = i;

  long long res = 0;
  while (m--) {
    int i;
    cin >> i;

    res += pos[i] / k + 1;
    if (pos[i]) {
      int p = pos[i];
      swap(pos[a[p]], pos[a[p - 1]]);
      swap(a[p], a[p - 1]);
    }
  }

  cout << res;
}
