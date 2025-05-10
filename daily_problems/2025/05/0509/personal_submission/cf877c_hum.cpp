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
  cout << n + n / 2 << endl;
  for (int i = 2; i <= n; i += 2) cout << i << " ";
  for (int i = 1; i <= n; i += 2) cout << i << " ";
  for (int i = 2; i <= n; i += 2) cout << i << " ";
}
