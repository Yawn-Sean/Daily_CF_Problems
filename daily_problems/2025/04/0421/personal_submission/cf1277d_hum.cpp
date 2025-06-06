#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void solve() {
  int n;
  cin >> n;
  vector<string> strs(n);
  for (int i = 0; i < n; i++) {
    cin >> strs[i];
  }
  set st(strs.begin(), strs.end());
  vector<int> w00, w10, w01, w11;
  for (int i = 0; i < n; i++) {
    if (strs[i][0] == '0') {
      if (strs[i].back() == '0') {
        w00.push_back(i);
      } else {
        w01.push_back(i);
      }
    } else {
      if (strs[i].back() == '1') {
        w11.push_back(i);
      } else {
        w10.push_back(i);
      }
    }
  }
  if (w00.size() && w11.size() && w01.empty() && w10.empty()) {
    cout << -1 << endl;
    return;
  }
  int c = w01.size() - w10.size();
  vector<int> res;
  while (c > 1) {
    int idx = w01.back();
    w01.pop_back();

    string s = strs[idx];
    ranges::reverse(s);

    if (!st.contains(s)) {
      res.emplace_back(idx);
      c -= 2;
    }
  }

  while (c < -1) {
    int idx = w10.back();
    w10.pop_back();
    string s = strs[idx];
    ranges::reverse(s);

    if (!st.contains(s)) {
      res.emplace_back(idx);
      c += 2;
    }
  }

  cout << res.size() << '\n';
  for (auto &x: res) cout << x + 1 << ' ';
  cout << '\n';
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
