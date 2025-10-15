/*
  https://codeforces.com/problemset/problem/140/C
  kaicheng
  2025-06-03
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define mod 1000000007 // 10^9 + 7
#define MOD 998244353  // 998244353
#define int long long

void solve() {
  int n;
  cin >> n;

  unordered_map<int, int> mp;
  for (int i = 0, x; i < n; ++i) {
    cin >> x;
    mp[x]++;
  }

  multiset<pair<int, int>> ms;
  for (auto &[val, f] : mp)
    ms.insert({f, val});

  vector<array<int, 3>> ans;

  while (ms.size() >= 3) {
    auto it1 = prev(ms.end());
    auto [f1, v1] = *it1;
    ms.erase(it1);

    auto it2 = prev(ms.end());
    auto [f2, v2] = *it2;
    ms.erase(it2);

    auto it3 = prev(ms.end());
    auto [f3, v3] = *it3;
    ms.erase(it3);

    array<int, 3> arr = {v1, v2, v3};
    sort(arr.begin(), arr.end(), greater<>());
    ans.push_back(arr);

    if (--f1 > 0)
      ms.insert({f1, v1});
    if (--f2 > 0)
      ms.insert({f2, v2});
    if (--f3 > 0)
      ms.insert({f3, v3});
  }

  cout << ans.size() << '\n';
  for (auto &[x, y, z] : ans)
    cout << x << ' ' << y << ' ' << z << '\n';
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt = 1;
  // cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}