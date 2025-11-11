#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<i64> nums(n);
    for (int i = 0; i < n; i++) {
      cin >> nums[i];
    }

    i64 ans = 0;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      v[i] = (nums[i] & 1) ? 1 : -1;
    }

    map<pair<int, int>, i64> cnt;
    cnt[{0, 0}] = 1;
    i64 pre = 0;
    for (int j = 1; j <= n; j++) {
      pre += v[j - 1];
      int target = (j - 1) & 3;
      ans += cnt[{target, pre - 1}];
      ans += cnt[{target, pre + 1}];
      cnt[{j & 3, pre}]++;
    }

    cout << ans << "\n";
  }
  return 0;
}
