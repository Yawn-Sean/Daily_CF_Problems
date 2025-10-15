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

  int n;
  cin >> n;

  vector<int> nums(n * 2);
  vector<int> mp(101);

  for (auto &v: nums)
    cin >> v, mp[v]++;

  vector<int> idx(n * 2);
  iota(idx.begin(), idx.end(), 0);

  ranges::sort(idx, [&](int i, int j) {
    return (mp[nums[i]] < mp[nums[j]] ? 1 : (mp[nums[i]] == mp[nums[j]] && nums[i] < nums[j]));
  });

  vector<int> cols(n * 2, 1);
  set<int> st1, st2;

  for (int i = 0; i < n * 2; i++) {
    if (i & 1) cols[idx[i]] = 2, st2.insert(nums[idx[i]]);
    else st1.insert(nums[idx[i]]);
  }

  cout << st1.size() * st2.size() << '\n';
  for (auto &x: cols) cout << x << ' ';
}
