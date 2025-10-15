#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, c;
  cin >> n >> c;
  int mod = 1e6 + 3;
  Binomial b(mod);
  cout << (b(n + c, c) - 1 + mod) % mod << '\n';
}