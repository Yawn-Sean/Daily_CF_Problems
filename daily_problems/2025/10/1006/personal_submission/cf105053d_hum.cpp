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

  long long n;
  cin >> n;

  if (n == 1) return cout << 'N', 0;

  vector<int> pws;

  for (int i = 2; i <= 1000000; i++) {
    if (n % i == 0) {
      pws.emplace_back(0);

      while (n % i == 0) {
        pws.back()++;
        n /= i;
      }
    }
  }

  if (n > 1) pws.emplace_back(1);

  if (pws.size() > 2) cout << 'N';
  else if (pws.size() == 1) cout << "NY"[pws[0] & 1];
  else if (max(pws[0], pws[1]) == 1) cout << 'Y';
  else cout << 'N';
}
