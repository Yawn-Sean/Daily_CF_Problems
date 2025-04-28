#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  map<int, int> mp;
  mp[-1] = -1;
  mp[1e9 + 5] = -1;
  mp[a[0]] = 0;
  vector<int> res;
  for (int i = 1; i < n; i++) {
    auto nex = mp.lower_bound(a[i]);
    auto pre = prev(nex);

    if (pre->second > nex->second) {
      res.push_back(pre->first);
    } else {
      res.push_back(nex->first);
    }
    mp[a[i]] = i;
  }
  for (int i = 0; i < n - 1; i++) {
    cout << res[i] << " \n"[i == n - 1];
  }
}
