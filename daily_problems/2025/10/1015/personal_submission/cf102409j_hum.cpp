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
  long long l;
  cin >> n >> l;

  vector<long long> nums(n + 1);
  nums[0] = 0, nums[n] = l;

  for (int i = 1; i <= n - 1; i++)
    cin >> nums[i];

  int p1 = 0, p2 = 0;
  long long ans = l;

  for (int i = 2; i <= n - 2; i++) {
    while (nums[p1 + 1] <= nums[i] - nums[p1 + 1]) p1++;
    while (nums[p2 + 1] - nums[i] <= l - nums[p2 + 1]) p2++;

    for (int d1 = p1; d1 <= p1 + 1; d1++) {
      for (int d2 = p2; d2 <= p2 + 1; d2++) {
        long long ma = max({nums[d1], nums[i] - nums[d1], nums[d2] - nums[i], l - nums[d2]});
        long long mi = min({nums[d1], nums[i] - nums[d1], nums[d2] - nums[i], l - nums[d2]});
        ans = min(ans, ma - mi);
      }
    }
  }

  cout << ans;
}
