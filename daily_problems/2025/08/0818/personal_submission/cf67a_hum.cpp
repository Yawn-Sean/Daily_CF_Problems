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
  string s;
  cin >> n >> s;
  vector res(n, 1);
  for (int i = 0; i < n - 1; i++) {
    if (s[i] == 'R') res[i + 1] = res[i] + 1;
    else if (s[i] == '=') res[i + 1] = res[i];
  }

  for (int i = n - 2; i >= 0; i--) {
    if (s[i] == 'L') res[i] = max(res[i], res[i + 1] + 1);
    else if (s[i] == '=') res[i] = res[i + 1];
  }

  for (int i = 0; i < n; i++) {
    cout << res[i] << " ";
  }
}
