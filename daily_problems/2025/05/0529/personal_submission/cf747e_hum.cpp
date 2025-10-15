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

  string s;
  cin >> s;

  string tmp;
  vector<string> strs;
  for (auto &c: s) {
    if (c == ',') {
      strs.push_back(tmp);
      tmp = "";
    } else tmp += c;
  }
  strs.push_back(tmp);

  ranges::reverse(strs);

  vector<vector<string>> res;
  function<void(int)> dfs = [&](int d) {
    string s = strs.back();
    strs.pop_back();
    if (res.size() < d) {
      res.emplace_back();
    }
    res[d - 1].push_back(s);
    int x = stoi(strs.back());
    strs.pop_back();
    for (int i = 0; i < x; i++) {
      dfs(d + 1);
    }
  };

  while (!strs.empty()) {
    dfs(1);
  }
  cout << res.size() << "\n";
  for (auto &v: res) {
    for (auto &s: v) {
      cout << s << " ";
    }
    cout << "\n";
  }
}
