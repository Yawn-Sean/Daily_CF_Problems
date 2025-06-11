/*
  https://codeforces.com/problemset/problem/768/C
  kaicheng
  2025-05-14
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define mod 1000000007 // 10^9 + 7
#define MOD 998244353  // 998244353

#define YES cout << "YES" << '\n'
#define NO cout << "NO" << '\n'
#define int long long
#define itn int

void solve() {
  int n, k, x;
  cin >> n >> k >> x;
  vector<int> a(n);
  for (auto &x : a)
    cin >> x;

  vector<vector<int>> his;
  his.push_back(a);
  sort(his.back().begin(), his.back().end());

  if (k == 0) {
    cout << *max_element(a.begin(), a.end()) << " "
         << *min_element(a.begin(), a.end()) << "\n";
    return;
  }

  int start = -1;
  for (int it = 1; it <= k; ++it) {
    vector<int> cur = his.back();
    for (int i = 0; i < n; i += 2)
      cur[i] ^= x;
    sort(cur.begin(), cur.end());

    auto found = find(his.begin(), his.end(), cur);
    if (found != his.end()) {
      start = found - his.begin();
      int len = it - start;
      k = start + (k - start) % len;
      break;
    }
    his.push_back(cur);
  }

  auto &ans = his[k];
  int max = *max_element(ans.begin(), ans.end());
  int min = *min_element(ans.begin(), ans.end());
  cout << max << ' ' << min << '\n';
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt;
  // cin >> tt;
  tt = 1;
  while (tt--) {
    solve();
  }
  return 0;
}