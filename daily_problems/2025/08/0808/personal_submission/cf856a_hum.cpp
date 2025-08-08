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

  int t;
  cin >> t;
  vector<int> vis(2000001, -1);
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    vector<int> b;
    for (int i = 1; i <= 1000000; i++) {
      bool f{true};
      for (int j = 0; j < n; j++) {
        if (vis[a[j] + i] == t) {
          f = false;
          break;
        }
      }
      if (f) {
        b.push_back(i);
        for (int j = 0; j < n; j++) {
          vis[a[j] + i] = t;
        }
      }
      if (b.size() == n) {
        break;
      }
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
      cout << b[i] << " ";
    }
    cout << endl;
  }
}
