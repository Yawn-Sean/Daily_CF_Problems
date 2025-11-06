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

  vector<int> nums(n);
  for (auto &v: nums) cin >> v;

  long long ans = 1e16, res;
  int cur;

  res = 0, cur = nums[0];

  for (int i = 1; i < n; i++) {
    if (i & 1) {
      cur = max(cur + 1, nums[i]);
      res += cur - nums[i];
    } else {
      cur = min(cur - 1, nums[i]);
      res += nums[i] - cur;
    }
  }

  ans = min(ans, res);

  res = 0, cur = nums[0];

  for (int i = 1; i < n; i++) {
    if (i & 1) {
      cur = min(cur - 1, nums[i]);
      res += nums[i] - cur;
    } else {
      cur = max(cur + 1, nums[i]);
      res += cur - nums[i];
    }
  }

  ans = min(ans, res);

  cout << ans;
}
