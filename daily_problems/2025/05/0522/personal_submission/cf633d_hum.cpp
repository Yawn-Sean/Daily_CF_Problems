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
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]]++;
  }
  int res = mp[0];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j || (a[i] == 0 && a[j] == 0)) {
        continue;
      }
      vector b{a[i], a[j]};
      mp[a[i]]--, mp[a[j]]--;
      while (true) {
        int x = b[b.size() - 1] + b[b.size() - 2];
        if (mp.contains(x) && mp[x] > 0) {
          b.push_back(x);
          mp[x]--;
        } else {
          break;
        }
      }
      res = max(res, (int) b.size());
      for (int x: b) {
        mp[x]++;
      }
    }
  }
  cout << res << endl;
}
