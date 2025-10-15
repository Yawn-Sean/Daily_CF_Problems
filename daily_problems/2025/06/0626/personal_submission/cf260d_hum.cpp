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
  vector<int> a(n);
  vector<int> ps0, ps1;
  for (int i = 0; i < n; i++) {
    int c;
    cin >> c >> a[i];
    if (c == 0) {
      ps0.push_back(i);
    } else {
      ps1.push_back(i);
    }
  }
  for (int i = 0; i < n - 1; i++) {
    int u = ps0.back();
    int v = ps1.back();
    int w = min(a[u], a[v]);
    a[u] -= w;
    a[v] -= w;
    cout << u + 1 << ' ' << v + 1 << ' ' << w << '\n';
    if (a[u] == 0 && ps0.size() > 1) {
      ps0.pop_back();
    } else {
      ps1.pop_back();
    }
  }
}
