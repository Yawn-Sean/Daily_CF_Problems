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
  map<int, vector<string>> mp;
  vector<pair<string, int>> res;
  for (int i = 0; i < n; i++) {
    string s;
    int x;
    cin >> s >> x;
    mp[x].push_back(s);
  }

  for (auto [k, v]: mp) {
    if (k > res.size()) {
      cout << -1;
      return 0;
    }
    for (auto &s: v) {
      for (int j = (int) res.size() - 1; j >= 0; j--) {
        if (res[j].second <= -k) {
          res[j].second -= 1;
        }
      }
      res.emplace_back(s, -k);
    }
  }
  for (auto &[s, x]: res) {
    cout << s << " " << x + n << '\n';
  }
}
