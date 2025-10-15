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
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n);
    vector<int> a(n), deg(n);
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < n; j++) {
        cin >> a[j];
        a[j]--;
      }
      for (int j = 1; j < n - 1; j++) {
        g[a[j]].push_back(a[j + 1]);
        deg[a[j + 1]]++;
      }
    }
    queue<int> que;
    for (int i = 0; i < n; i++) {
      if (deg[i] == 0) {
        que.push(i);
      }
    }
    int cnt{};
    while (!que.empty()) {
      int u = que.front();
      que.pop();
      cnt++;
      for (int v: g[u]) {
        deg[v]--;
        if (deg[v] == 0) {
          que.push(v);
        }
      }
    }
    cout << (cnt == n ? "YES" : "NO") << '\n';
  }
}
