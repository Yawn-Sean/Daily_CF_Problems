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
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  ranges::sort(a);
  k--;
  int i = 0, j;

  while (i < n) {
    j = i;
    while (j < n && a[i] == a[j])
      j++;
    if (k < 1ll * (j - i) * n) break;
    k -= 1ll * (j - i) * n;
    i = j;
  }

  cout << a[i] << ' ' << a[k / (j - i)];
}
