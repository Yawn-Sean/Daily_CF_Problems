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
    int n, c0 = 0, c1 = 0;
    cin >> n;

    while (n--) {
      string s;
      cin >> s;

      if (s.contains("xxx")) {
        c1 ^= 1;
      } else if (s.contains("xx"))
        c0 ^= 1;
    }
    cout << ((c0 | c1) ? "Monocarp" : "Polycarp") << '\n';
  }
}
