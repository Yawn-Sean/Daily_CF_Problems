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

  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  ranges::sort(a, greater{});

  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      cout << i + 1 << " ";
      for (int l = 0; l < i; l++) {
        cout << a[l] << " ";
      }
      cout << a[j] << endl;
      if (--k == 0) {
        return 0;
      }
    }
  }
}
