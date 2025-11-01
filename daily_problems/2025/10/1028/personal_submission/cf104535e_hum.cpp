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

  cout << -1 << ' ' << 2 << '\n';
  cout << 0 << ' ' << 2 << '\n';
  cout << n - 1 << ' ' << 1 << '\n';
  cout << n << ' ' << 0 << '\n';
  cout << n - 1 << ' ' << 0 << '\n';
  cout << 0 << ' ' << 1 << '\n';
}
