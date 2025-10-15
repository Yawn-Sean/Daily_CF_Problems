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
  ifstream cin("input.txt");
  ofstream cout("output.txt");

  string a, b;
  cin >> a >> b;
  int n = a.size();
  vector<int> c1(26), c2(26), cnt1(26), cnt2(26);
  for (int i = 0; i < n; i++) {
    c1[a[i] - 'A']++;
    c2[b[i] - 'A']++;
  }
  int res{};
  for (int i = 0; i < 26; i++) {
    int t = abs(c1[i] - c2[i]);
    res += t;
    if (c1[i] >= c2[i]) {
      cnt1[i] = t;
    } else {
      cnt2[i] = t;
    }
  }

  cout << res / 2 << '\n';
  for (int i = 0; i < n; i++) {
    int c = a[i] - 'A';
    c1[c]--;
    if (cnt1[c]) {
      for (int j = 0; j < 26; j++) {
        if (j >= c && c1[c] >= cnt1[c]) {
          break;
        }
        if (cnt2[j]) {
          cnt1[c]--;
          cnt2[j]--;
          a[i] = 'A' + j;
          break;
        }
      }
    }
  }
  cout << a << '\n';
}
