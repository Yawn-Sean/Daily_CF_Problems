#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 998244353;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  auto check = [&](vector<int> nums, bool flag) {
    bool cur = flag;
    i64 cost = 0;
    for (int i = 1; i < n; i++) {
      if (cur) {
        if (nums[i] <= nums[i - 1]) {
          cost += nums[i - 1] - nums[i] + 1;
          nums[i] = nums[i - 1] + 1;
        }
      } else {
        if (nums[i] >= nums[i - 1]) {
          cost += nums[i] - nums[i - 1] + 1;
          nums[i] = nums[i - 1] - 1;
        }
      }
      cur = !cur;
    }
    return cost;
  };

  i64 ans = min(check(nums, true), check(nums, false));
  cout << ans << '\n';
  return 0;
}
