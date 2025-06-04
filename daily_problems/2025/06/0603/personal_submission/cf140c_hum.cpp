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
  unordered_map<int, int> mp;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    mp[a[i]]++;
  }
  priority_queue<array<int, 2>> pq;
  for (auto [x, y]: mp) {
    pq.push({y, x});
  }
  vector<int> res;
  while (pq.size() >= 3) {
    vector<array<int, 2>> tmp;
    for (int i = 0; i < 3; i++) {
      auto [y, x] = pq.top();
      pq.pop();
      tmp.push_back({y - 1, x});
    }

    for (int i = 0; i < 3; i++) {
      res.push_back(tmp[i][1]);
      if (tmp[i][0] > 0) {
        pq.push({tmp[i]});
      }
    }
  }
  cout << res.size() / 3 << '\n';
  for (int i = 0; i < res.size(); i += 3) {
    array<int, 3> tmp{};
    for (int j = 0; j < 3; j++) {
      tmp[j] = res[i + j];
    }
    ranges::sort(tmp, greater<int>{});
    cout << tmp[0] << ' ' << tmp[1] << ' ' << tmp[2] << '\n';
  }
}
