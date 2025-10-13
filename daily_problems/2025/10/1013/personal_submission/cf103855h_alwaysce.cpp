#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1000000007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> nums(n);

  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  /*
    dp[i] = sum(dp[j]) if preMx[j] < preMx[i] for all j < i
    = 1 + sum(dp[j]) if preMx[j] < preMx[i] for all j < i, j >= 0

    可以简化为 两段前缀最大值之间的分点方案乘积
  */
  int mx = 0, pre = 0;
  i64 ans = 1;
  for (int i = 0; i < n; i++) {
    if (nums[i] > mx) {
        ans = ans * (1ll * (i - pre + 1)) % mod;
        mx = nums[i];
        pre = i;
    }
  }

  cout << ans % mod << "\n";
  return 0;
}
