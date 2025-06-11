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
  int n;
  cin >> n;
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  array<int, 2> res{};
  int p{};
  for (int i = 0; i < s.size(); i++) {
    for (const string &t: a) {
      if (t.size() <= i + 1 && s.substr(i + 1 - t.size(), t.size()) == t) {
        p = max(p, i + 2 - (int) t.size());
      }
    }
    if (i - p + 1 > res[0]) {
      res[0] = i - p + 1;
      res[1] = p;
    }
  }
  cout << res[0] << " " << res[1] << "\n";
}
