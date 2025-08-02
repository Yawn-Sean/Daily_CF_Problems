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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> fac(n + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j * j <= i; j++) {
      if (i % j == 0) {
        if (j != 1) {
          fac[i].push_back(j);
        }
        if (j * j != i) {
          fac[i].push_back(i / j);
        }
      }
    }
  }
  set<int> s, f;
  vector g(n + 1, -1);
  while (m--) {
    char t;
    int x;
    cin >> t >> x;
    if (t == '+') {

      if (s.contains(x)) {
        cout << "Already on" << endl;
      } else {
        bool flag{true};
        for (int d: fac[x]) {
          if (f.contains(d)) {
            cout << "Conflict with " << g[d] << endl;
            flag = false;
            break;
          }
        }
        if (flag) {
          cout << "Success" << endl;
          s.insert(x);
          for (int d: fac[x]) {
            f.insert(d);
            g[d] = x;
          }
        }
      }
    } else {
      if (!s.contains(x)) {
        cout << "Already off" << endl;
      } else {
        cout << "Success" << endl;
        s.erase(x);
        for (int d: fac[x]) {
          f.erase(d);
          g[d] = -1;
        }
      }
    }
  }
}
