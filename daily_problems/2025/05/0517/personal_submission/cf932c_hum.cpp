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

  int n, a, b;
  cin >> n >> a >> b;
  for (int x = 0; x * a <= n; x++) {
    if ((n - x * a) % b == 0) {
      int y = (n - x * a) / b;
      for (int i = 0; i < x; i++) {
        int s{a * i};
        for (int j = 1; j < a; j++) {
          cout << s + j + 1 << " ";
        }
        cout << s + 1 << " ";
      }
      for (int i = 0; i < y; i++) {
        int s{a * x + b * i};
        for (int j = 1; j < b; j++) {
          cout << s + j + 1 << " ";
        }
        cout << s + 1 << " ";
      }
      return 0;
    }
  }
  cout << -1 << endl;
}
