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
  set<array<int, 2>> st;
  for (int i = 0; i < n; i++) {
    int k, b;
    cin >> k >> b;
    if (k) {
      int g = gcd(k, b);

      k /= g;
      b /= g;
      if (k < 0) {
        k *= -1;
        b *= -1;
      }
      st.insert({k, b});
    }
  }
  cout << st.size() << endl;
}
