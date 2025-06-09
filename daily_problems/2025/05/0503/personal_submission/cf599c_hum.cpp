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
  vector<int> b = a;
  ranges::sort(b);
  map<int, int> mp;
  int c{}, res{};
  for (int i = 0; i < n; i++) {
    mp[b[i]]++;
    if (mp[b[i]] == 1) {
      c++;
    }
    mp[a[i]]--;
    if (mp[a[i]] == 0) {
      c--;
    }
    if (c == 0) {
      res++;
    }
  }
  cout << res << endl;
}
