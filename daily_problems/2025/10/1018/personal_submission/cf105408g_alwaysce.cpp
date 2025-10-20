#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;

  vector<int> nums(n);
  int g = 0;
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
    g = gcd(g, nums[i]);
  }

  for (auto& x : nums) {
    x /= g;
  }

  bool ok = true;

  int MX = *max_element(nums.begin(), nums.end());
  vector<int> spf(MX + 1);
  iota(spf.begin(), spf.end(), 0);

  for (int i = 2; i <= MX; i++) {
    if (spf[i] == i) {
      for (int j = i * 2; j <= MX; j += i) {
        spf[j] = i;
      }
    }
  }

  vector<int> vis(MX + 1, 0);
  for (auto& x : nums) {
    while (x > 1) {
      int p = spf[x];
      if (vis[p]) {
        ok = false;
        break;
      }
      vis[p] = 1;
      while (x % p == 0) {
        x /= p;
      }
    }
    if (!ok) break;
  }

  cout << (ok ? "YES\n" : "NO\n");
  return 0;
}
