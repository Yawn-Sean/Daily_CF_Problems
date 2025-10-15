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
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> v0, v1;
  for (int v: a) {
    int t = sqrt(v);
    if (t * t == v) {
      if (t != 0) {
        v0.push_back(1);
      } else {
        v0.push_back(2);
      }
    } else {
      v1.push_back(min(v - t * t, (t + 1) * (t + 1) - v));
    }
  }
  ranges::sort(v0);
  ranges::sort(v1);
  long long res{};
  if (v0.size() > v1.size()) {
    for (int i = 0; i < (v0.size() - v1.size()) / 2; i++) {
      res += v0[i];
    }
  } else {
    for (int i = 0; i < (v1.size() - v0.size()) / 2; i++) {
      res += v1[i];
    }
  }
  cout << res << endl;
}
