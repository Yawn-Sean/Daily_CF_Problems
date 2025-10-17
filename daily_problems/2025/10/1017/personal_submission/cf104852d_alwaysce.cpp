#include <bits/stdc++.h>
using namespace std;
using i64 = long long;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;

  // 从后往前
  vector<int> digits;
  int tmp = n;
  while (tmp > 0) {
    digits.push_back(tmp % 10);
    tmp /= 10;
  }

  int m = digits.size();
  vector<i64> nums = {0};

  // 假设钦定了数字a和数字b的构成
  for (int d1 = 0; d1 <= 9; d1++) {
    for (int d2 = 0; d2 <= 9; d2++) {
      if (d1 == 0 && d2 == 0) {
        continue;
      }

      for (int L = 1; L <= m; L++) {
        int tot = (1 << L);
        for (int mask = 0; mask < tot; mask++) {
          int msb = (mask >> (L - 1)) & 1;
          int first = msb ? d2 : d1;
          if (first == 0) {
            continue;
          }

          if (d1 != d2 && (mask == 0 || mask == tot - 1)) {
            continue;
          }

          i64 val = 0;
          for (int pos = L - 1; pos >= 0; --pos) {
            int bit = (mask >> pos) & 1;
            int digit = bit ? d2 : d1;
            val = val * 10ll + digit;
          }

          if (L < m || val <= n) {
            nums.push_back(val);
          }
        }
      }
    }
  }

  sort(nums.begin(), nums.end());
  nums.erase(unique(nums.begin(), nums.end()), nums.end());
  
  int ans = 0;
  for (auto& x: nums) {
    if (x > n) { break; }
    i64 b = n - x;
    if (b < x) {
      continue;
    }
    if (binary_search(nums.begin(), nums.end(), b)) {
      ++ans;
    }
  }
  cout << ans << "\n";
  return 0;
}
