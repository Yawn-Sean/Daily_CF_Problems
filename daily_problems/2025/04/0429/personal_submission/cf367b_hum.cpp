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

  int n, m, p;
  cin >> n >> m >> p;
  vector<int> a(n), b(m);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  map<int, int> mp;
  for (int i = 0; i < m; i++) {
    cin >> b[i];
    mp[b[i]]++;
  }
  int c = mp.size();
  vector<long long> res;
  for (int i = 0; i < p; i++) {
    map<int, int> cur;
    int t{};
    for (int j = i; j < n; j += p) {
      cur[a[j]]++;
      // if (mp.contains(a[j])) {
      //   if (cur[a[j]] == mp[a[j]]) {
      //     t++;
      //   }
      //   if (cur[a[j]] == mp[a[j]] + 1) {
      //     t--;
      //   }
      // }
      long long pre = j - (long long) (m - 1) * p;
      if (pre >= 0) {
        if (mp == cur) {
          res.push_back(pre);
        }
        // if (c == t) {
        //   res.push_back(pre);
        // }
        // if (mp.contains(a[pre]) && cur[a[pre]] == mp[a[pre]]) {
        //   t--;
        // }
        // if (mp.contains(a[pre]) && cur[a[pre]] == mp[a[pre]] + 1) {
        //   t++;
        // }
        if (cur[a[pre]] == 1) {
          cur.erase(a[pre]);
        } else {
          cur[a[pre]]--;
        }
      }
    }
  }
  cout << res.size() << endl;
  ranges::sort(res);
  for (auto i: res) {
    cout << i + 1 << " ";
  }
}
