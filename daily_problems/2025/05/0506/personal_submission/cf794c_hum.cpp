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

  string s, t;
  cin >> s >> t;
  int n = s.size();
  ranges::sort(s);
  ranges::sort(t, ranges::greater{});
  deque<char> d1, d2;
  for (int i = 0; i < (n + 1) / 2; i++) {
    d1.push_back(s[i]);
    d2.push_back(t[i]);
  }
  if (n % 2) {
    d2.pop_back();
  }
  vector<char> res(n);
  int l{}, r{n - 1};
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      if (d1.front() >= d2.front()) {
        res[r--] = d1.back();
        d1.pop_back();
      } else {
        res[l++] = d1.front();
        d1.pop_front();
      }
    } else {
      if (d1.front() >= d2.front()) {
        res[r--] = d2.back();
        d2.pop_back();
      } else {
        res[l++] = d2.front();
        d2.pop_front();
      }
    }
  }
  cout << string(res.begin(), res.end()) << '\n';
}
