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

  int r, b;
  cin >> r >> b;
  if (r == b) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
