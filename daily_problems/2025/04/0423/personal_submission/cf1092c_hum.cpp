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

  vector<string> strs, tmp;
  int n;
  cin >> n;
  for (int i = 0; i < n * 2 - 2; i++) {
    string s;
    cin >> s;
    strs.push_back(s);
    if (s.size() == n - 1) {
      tmp.push_back(s);
    }
  }

  string res{};
  function<bool(string)> check = [&](string s) {
    res = "";
    set<string> pre, suf;
    for (int i = 0; i < n; i++) {
      pre.insert(s.substr(0, i + 1));
      suf.insert(s.substr(n - i - 1, n));
    }
    for (int i = 0; i < n * 2 - 2; i++) {
      if (pre.contains(strs[i])) {
        res += "P";
        pre.erase(strs[i]);
      } else if (suf.contains(strs[i])) {
        res += "S";
        suf.erase(strs[i]);
      } else {
        return false;
      }
    }
    return true;
  };
  if (check(tmp[0] + tmp[1].back())) {
    cout << res << endl;
  } else {
    check(tmp[1] + tmp[0].back());
    cout << res << endl;
  }
}
