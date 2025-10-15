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
  vector<int> h(n + 1);
  for (int i = 0; i <= n; i++) {
    cin >> h[i];
  }
  for (int i = 0; i < n; i++) {
    if (h[i] > 1 && h[i + 1] > 1) {
      cout << "ambiguous" << endl;
      int cur = 0;
      cout << cur << " ", cur += h[0];
      for (int j = 1; j <= n; j++) {
        for (int k = 0; k < h[j]; k++) {
          cout << cur << " ";
        }
        cur += h[j];
      }
      cout << endl;
      cur = 0, cout << cur << " ", cur += h[0];
      for (int j = 1; j <= n; j++) {
        if (h[j] > 1 && h[j - 1] > 1) {
          cout << cur - 1 << " ";
          for (int k = 0; k < h[j] - 1; k++) {
            cout << cur << " ";
          }
        } else {
          for (int k = 0; k < h[j]; k++)
            cout << cur << " ";
        }
        cur += h[j];
      }
      return 0;
    }
  }
  cout << "perfect" << endl;
}
