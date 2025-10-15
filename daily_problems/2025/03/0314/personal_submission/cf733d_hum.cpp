#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<array<int, 3>> a(n);
  vector<int> res(3);
  map<array<int, 2>, int> mp;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> a[i][j];
    }
    ranges::sort(a[i]);
    if (a[i][0] > res[0]) {
      res[0] = a[i][0];
      res[1] = i;
      res[2] = -1;
    }
    if (auto it = mp.find({a[i][1], a[i][2]}); it != mp.end()) {
      if (min(a[it->second][0] + a[i][0], a[i][1]) > res[0]) {
        res[0] = min(a[it->second][0] + a[i][0], a[i][1]);
        res[1] = it->second;
        res[2] = i;
      }
      if (a[i][0] > a[it->second][0]) {
        // mp[{a[i][1], a[i][2]}] = i;
        it->second = i;
      }
    } else {
      mp[{a[i][1], a[i][2]}] = i;
    }
  }
  if (res[2] != -1) {
    cout << 2 << endl;
    cout << res[1] + 1 << " " << res[2] + 1 << endl;
  } else {
    cout << 1 << endl;
    cout << res[1] + 1 << endl;
  }

}
