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

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n <= 5) {
      cout << n / 2 + 1 << endl;
      for (int i = 1; i <= n; ++i) {
        cout << i / 2 + 1 << ' ';
      }
      cout << endl;
    } else {
      cout << 4 << endl;
      for (int i = 0; i < n; ++i) {
        cout << (i % 4) + 1 << ' ';
      }
      cout << endl;
    }
  }
}
