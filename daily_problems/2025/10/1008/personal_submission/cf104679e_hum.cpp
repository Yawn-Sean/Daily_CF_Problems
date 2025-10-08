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


  int M = 1e7;

  vector is_prime(M + 1, 1);
  is_prime[0] = 0, is_prime[1] = 0;

  for (int i = 2; i <= M; i++) {
    if (is_prime[i]) {
      for (int j = i * 2; j <= M; j += i) {
        is_prime[j] = 0;
      }
    }
  }

  for (int i = 1; i <= M; i++) {
    is_prime[i] += is_prime[i - 1];
  }

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    if (n <= 3) cout << n - 2 << '\n';
    else cout << is_prime[n] - is_prime[n / 2] << '\n';
  }
}
