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
  if (n == 1 && m == 1) {
    cout << 1 << endl;
    return 0;
  }
  if (n + m < 5) {
    cout << -1 << endl;
    return 0;
  }

  int mi = 1;
  int ma = n * m / 2 + 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if ((i + j) % 2 == 1) {
        cout << mi++ << " ";
      } else {
        cout << ma++ << " ";
      }
    }
    cout << endl;
  }
}
