#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

vector<int> prep(string s) {
  int n = s.size();
  vector pi(n, 0);

  int j = 0;
  for (int i = 1; i < n; i++) {
    while (j && s[j] != s[i]) j = pi[j - 1];
    if (s[j] == s[i]) j++;
    pi[i] = j;
  }

  return pi;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string s, t;
  int k;
  getline(cin, s);
  getline(cin, t);
  cin >> k;
  int l = 0, r = s.size();
  while (l < r) {
    int m = l + r + 1 >> 1;
    string tmp = t.substr(0, m);
    vector<int> pi = prep(tmp + "#" + s);
    int cnt = 0;
    for (int len: pi) {
      if (len == m) {
        cnt++;
      }
    }
    if (cnt >= k) {
      l = m;
    } else {
      r = m - 1;
    }
  }
  if (l) {
    cout << t.substr(0, l) << endl;
  } else {
    cout << "IMPOSSIBLE" << endl;
  }
}
