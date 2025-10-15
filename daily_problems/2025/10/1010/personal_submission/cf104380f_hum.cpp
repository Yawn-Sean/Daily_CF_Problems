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

  int n, l, r;
  cin >> n >> l >> r;

  vector<int> nums(n);
  for (auto &v: nums) cin >> v;

  int x = min(n - r, l - 1);
  while (x--)
    nums.pop_back();

  sort(nums.rbegin(), nums.rend());

  long long ans = 0;
  for (int i = 0; i <= r - l; i++)
    ans += nums[i];

  cout << ans;
}
