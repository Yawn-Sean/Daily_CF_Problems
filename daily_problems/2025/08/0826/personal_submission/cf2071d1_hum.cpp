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


  int t;
  cin >> t;

  while (t--) {
    int n;
    long long l, r;
    cin >> n >> l >> r;

    vector<int> nums(n);
    for (auto &x: nums) cin >> x;

    if (n % 2 == 0) {
      int v = 0;
      for (int i = 0; i < n / 2; i++)
        v ^= nums[i];
      nums.emplace_back(v);
      n++;
    }

    int total = 0;
    for (auto &v: nums) {
      total ^= v;
    }

    function<int(long long)> solve = [&](long long x) -> int {
      if (x <= n) return nums[x - 1];

      if (x <= n * 2) {
        int res{};
        for (int i = 0; i < x / 2; i++)
          res ^= nums[i];
        return res;
      }

      long long v = x / 2;
      if (v % 2 == 0) return total ^ solve(v);
      return total;
    };

    cout << solve(l) << '\n';
  }
}
