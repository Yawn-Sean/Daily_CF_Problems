#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k, p;
  cin >> n >> k >> p;
  vector<int> a(n), o, e;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i] % 2 == 0) {
      e.push_back(a[i]);
    } else {
      o.push_back(a[i]);
    }
  }
  vector<vector<int>> res(k);
  for (int i = 0; i < k - p; ++i) {
    if (o.empty()) {
      cout << "NO" << endl;
      return 0;
    }
    res[i].push_back(o.back());
    o.pop_back();
  }

  for (int i = 0; i < p; ++i) {
    if (!e.empty()) {
      res[k - p + i].push_back(e.back());
      e.pop_back();
    } else {
      if (o.size() >= 2) {
        res[k - p + i].push_back(o.back());
        o.pop_back();
        res[k - p + i].push_back(o.back());
        o.pop_back();
      } else {
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  if (o.size() % 2 == 1) {
    cout << "NO" << endl;
    return 0;
  }

  while (!o.empty()) {
    res[0].push_back(o.back());
    o.pop_back();
  }
  while (!e.empty()) {
    res[0].push_back(e.back());
    e.pop_back();
  }

  cout << "YES" << endl;
  for (int i = 0; i < k; ++i) {
    cout << res[i].size() << " ";
    for (int v: res[i]) {
      cout << v << " ";
    }
    cout << endl;
  }
}
