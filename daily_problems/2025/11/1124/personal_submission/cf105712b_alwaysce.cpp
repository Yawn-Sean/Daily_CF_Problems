#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 998244353;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> nums(n);
    i64 tot = 0;
    int cnt = 0;
    bool has_pair = false;

    for (int i = 0; i < n; i++) {
      cin >> nums[i];
      tot += nums[i];
      if (nums[i] >= 2) {
        has_pair = true;
      }
      if (nums[i] > 0) {
        cnt++;
      }
    }

    if (n == 2) {
      i64 diff = abs(nums[0] - nums[1]);
      if (diff % 3 == 0) {
        cout << max(0ll, tot - 2);
      } else {
        cout << max(0ll, tot - 1);
      }
    } else {
      if (!has_pair) {
        cout << 0;
      } else if (cnt == 1 && tot == 3) {
        cout << 1;
      } else {
        cout << tot - 1;
      }
    }
    cout << "\n";
  }

  return 0;
}
