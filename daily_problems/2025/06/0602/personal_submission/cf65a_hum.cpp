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
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  if (a * c * e < b * d * f || (!a && b && d) || (!c && d)) {
    cout << "Ron";
  } else {
    cout << "Hermione";
  }
}
