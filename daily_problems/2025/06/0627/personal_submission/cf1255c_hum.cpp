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

  int n;
  cin >> n;

  vector<array<int, 3>> q(n - 2);
  for (int i = 0; i < n - 2; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> q[i][j];
      q[i][j]--;
    }
  }

  vector a(n, vector<int>());
  for (int i = 0; i < n - 2; i++) {
    for (int j = 0; j < 3; j++) {
      a[q[i][j]].push_back(i);
    }
  }

  vector<int> p(n);
  vector<bool> used(n);

  for (int i = 0; i < n; i++) {
    if (a[i].size() == 1) {
      p[0] = i;
      used[p[0]] = true;
      break;
    }
  }

  for (auto i: a[p[0]]) {
    for (int j = 0; j < 3; j++) {
      if (a[q[i][j]].size() == 2) {
        p[1] = q[i][j];
        break;
      }
    }
    used[p[1]] = true;
  }
  for (int i = 2; i < n; i++) {
    for (auto j: a[p[i - 2]]) {
      for (int k = 0; k < 3; k++) {
        if (not used[q[j][k]]) {
          p[i] = q[j][k];
        }
      }
    }
    used[p[i]] = true;
  }
  for (auto i: p) {
    cout << i + 1 << " ";
  }
}
