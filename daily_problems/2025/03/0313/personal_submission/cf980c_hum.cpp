#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<int> vis(256, -1);
  vector<int> res(n);
  for (int i = 0; i < n; i++) {
    if (vis[a[i]] != -1) {
      res[i] = vis[a[i]];
      continue;
    }

    int l = max(0, a[i] - k + 1);

    for (; l <= a[i]; l++) {
      if (l - 1 >= 0 && vis[l] == vis[l - 1] && vis[l - 1] != -1) {
      } else {
        break;
      }
    }
    for (int j = l; j <= a[i]; j++) {
      vis[j] = l;
    }
    res[i] = vis[a[i]];
  }
  for (int i = 0; i < n; i++) {
    cout << res[i] << " ";
  }
}
