#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  map<char, vector<int>> mp;
  for (int i = 0; i < n; ++i) {
    mp[s[i]].push_back(i);
  }
  int ans = 0;
  for (auto &[k, v]: mp) {
    int res = 0;
    for (int p = 0; p < n; p++) {
      map<char, int> cnt;
      for (auto &x: v)
        cnt[s[(x + p) % n]]++;

      int cur = 0;
      for (auto &[_, c]: cnt)
        cur += (c == 1);

      res = max(res, cur);
    }
    ans += res;
  }

  cout << fixed << setprecision(10) << 1.0 * ans / n;
}
