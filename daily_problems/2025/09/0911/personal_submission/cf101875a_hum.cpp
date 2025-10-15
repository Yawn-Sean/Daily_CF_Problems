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
  long long g = gcd(n, k);

  cout << k * (n - g) + (k - 1) * (g - 1);
}
