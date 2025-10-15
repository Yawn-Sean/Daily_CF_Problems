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
  int d, saved;
  cin >> d;

  saved = d;

  while (d % 2 == 0) d /= 2;
  while (d % 5 == 0) d /= 5;

  int cur = 0, tot = 0;

  for (int i = 1; i <= 1000000; i++) {
    cur = (10ll * cur + 9) % d;
    tot = (tot + 9) % saved;

    if (cur == 0 && tot == 0)
      return cout << string(i, '9') << string(10, '0'), 0;
  }
}
