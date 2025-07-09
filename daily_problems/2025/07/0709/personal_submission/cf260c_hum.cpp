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

  int n, x;
  cin >> n >> x;
  vector<long long> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  long long m = ranges::min(a);
  for (int i = 0; i < n; i++) {
    a[i] -= m;
  }
  m *= n;
  x--;
  while (a[x]) {
    a[x]--;
    m++;
    x = (x - 1 + n) % n;
  }
  a[x] = m;
  for (auto i: a) {
    cout << i << " ";
  }
  cout << '\n';
}
