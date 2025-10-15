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
  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }
  if (n - 1 == a) {
    cout << -1 << endl;
    return 0;
  }
  int s{1};
  cout << s << " ";
  for (int i = 0; i < b; i++) {
    cout << s * 2 << " ";
    s *= 2;
  }
  for (int i = 0; i < n - a - b - 1; i++) {
    cout << s << " ";
  }
  for (int i = 0; i < a; i++) {
    cout << ++s << " ";
  }
  cout << endl;
}
