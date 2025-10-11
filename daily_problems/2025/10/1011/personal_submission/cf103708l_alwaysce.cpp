#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1000000007;
static inline i64 norm(i64 x) {
  x %= mod;
  if (x < 0) x += mod;
  return x;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  vector<int> L(n, -1), R(n, n);
  {
    vector<int> stk;
    for (int i = 0; i < n; i++) {
      while (!stk.empty() && nums[stk.back()] <= nums[i]) {
        stk.pop_back();
      }
      L[i] = (stk.empty() ? -1 : stk.back());
      stk.push_back(i);
    }
  }

  {
    vector<int> stk;
    for (int i = n - 1; i >= 0; i--) {
      while (!stk.empty() && nums[stk.back()] <= nums[i]) {
        stk.pop_back();
      }
      R[i] = (stk.empty() ? n : stk.back());
      stk.push_back(i);
    }
  }
  i64 ans = 0;

  vector<i64> S(n + 1), SS(n + 1);
  for (int k = 1; k <= n; k++) {
    S[k] = norm(S[k - 1] + nums[k - 1]);
  }
  for (int k = 1; k <= n; k++) {
    SS[k] = norm(SS[k - 1] + 1ll * (k - 1) * nums[k - 1]);
  }


  for (int i = 0; i < n; i++) {
    int l = L[i], r = R[i];

    i64 left_cnt = i - l;
    i64 right_cnt = r - i;

    /*
      for j in range(l[i] + 1, i - 1)
        (j - l[i]) * nums[j]
      = (SS[i] - SS[l[i]+1]) - left[i] * (S[i] - S[l + 1])  
    */

    i64 add = norm(nums[i] * left_cnt % mod * right_cnt % mod);
    ans = norm(ans + add);

    add = norm(((SS[i] - SS[l + 1]) % mod - (S[i] - S[l + 1]) % mod * l % mod) * right_cnt % mod);
    ans = norm(ans + add);

    add = norm(((S[r] - S[i + 1]) % mod * r % mod - (SS[r] - SS[i + 1]) % mod) * left_cnt % mod);
    ans = norm(ans + add);
  }

  cout << ans % mod << endl;
  return 0;
}
