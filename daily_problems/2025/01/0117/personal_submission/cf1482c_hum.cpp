#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(m);
    vector<int> res(m), cnt(n + 1);
    int v = 0;

    for (int i = 0; i < m; i++) {
      int k;
      cin >> k;
      g[i].resize(k);
      for (int j = 0; j < k; j++) {
        cin >> g[i][j];
      }
      res[i] = g[i][0];
      cnt[res[i]] += 1;
      if (cnt[res[i]] > cnt[v]) {
        v = res[i];
      }
    }
    int can = (m + 1) / 2;
    for (int i = 0; i < m; i++) {
      if (res[i] == v && cnt[v] > can && g[i].size() > 1) {
        res[i] = g[i][1];
        cnt[v]--;
      }
    }

    if (cnt[v] > can) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      for (int i = 0; i < m; i++) {
        cout << res[i] << " ";
      }
      cout << "\n";
    }
  }
}
