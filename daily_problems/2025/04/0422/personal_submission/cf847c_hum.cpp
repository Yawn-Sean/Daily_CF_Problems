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

  long long n, k;
  cin >> n >> k;
  if (n * (n - 1) / 2 < k) {
    cout << "Impossible" << endl;
    return 0;
  }
  function<void(long long, long long)> dfs = [&](long long n, long long k) {
    if (n == 0) {
      return;
    }
    if (n - 1 <= k) {
      cout << "(";
      dfs(n - 1, k - (n - 1));
      cout << ")";
    } else {
      cout << "()";
      dfs(n - 1, k);
    }
  };
  dfs(n, k);
}
