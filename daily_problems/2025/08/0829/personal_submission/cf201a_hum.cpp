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
  int x;
  cin >> x;
  if (x == 3) {
    cout << "5" << endl;
    return 0;
  }
  int n = 1;
  while ((n * n + 1) / 2 < x) {
    n += 2;
  }

  cout << n << endl;
}
