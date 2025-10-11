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

  vector<int> nums(n), ops;
  for (auto &x: nums) cin >> x;

  for (int i = n - 1; i >= 0; i--) {
    bool flg = false;
    for (int j = i; j >= 0; j--) {
      if (nums[j] == j + 1) {
        flg = true;
        ops.emplace_back(nums[j]);
        nums.erase(nums.begin() + j);
        break;
      }
    }
    if (!flg) return cout << "NO", 0;
  }

  reverse(ops.begin(), ops.end());

  cout << "YES\n";
  for (auto &op: ops) cout << op << ' ';
}
