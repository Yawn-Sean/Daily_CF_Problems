#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  map<string, vector<int>> mp;
  for (int i = 0; i < n; ++i) {
    string s;
    int v;
    cin >> s >> v;
    mp[s].push_back(v);
  }

  for (auto &v: mp | views::values) {
    ranges::sort(v);
  }
  int res = 0, mid = 0;
  for (auto &[s,v]: mp) {
    string rev_s = s;
    ranges::reverse(rev_s);
    if (s == rev_s) {
      while (v.size() > 1 && v[v.size() - 1] + v[v.size() - 2] > 0) {
        res += v[v.size() - 1] + v[v.size() - 2];
        mid = max(mid, -v[v.size() - 2]);
        v.pop_back(), v.pop_back();
      }
      if (!v.empty()) {
        mid = max(mid, v.back());
      }
    } else if (mp.contains(rev_s)) {
      vector<int> &rev_v = mp[rev_s];
      while (!v.empty() && !rev_v.empty() && v.back() + rev_v.back() > 0) {
        res += v.back() + rev_v.back();
        v.pop_back(), rev_v.pop_back();
      }
    }
  }
  cout << res + mid << '\n';
}
