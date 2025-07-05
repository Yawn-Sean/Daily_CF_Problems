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
  int n;
  cin >> n;
  int k = 32 - __builtin_clz(n - 1);
  cout << k << '\n';
  for (int i = 0; i < k; i++) {
    vector<int> tmp;
    for (int j = 0; j < n; j++) {
      if (j >> i & 1) {
        tmp.push_back(j);
      }
    }
    cout << tmp.size() << '\n';
    for (auto &x: tmp) {
      cout << x << ' ';
    }
    cout << '\n';
  }
}
