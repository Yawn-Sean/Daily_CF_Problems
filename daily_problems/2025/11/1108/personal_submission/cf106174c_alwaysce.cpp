#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  i64 n;
  cin >> n;
  i64 k;
  cin >> k;

  // 从1开始连续写x个数字的总位数
  auto calc = [&](i64 x) {
    i64 start = 1;
    int d = 1;
    i64 ans = 0;
    for (int i = 0; i < 18; i++) {
      if (start > x) {
        break;
      }
      ans += min(start * 9, x - start + 1) * d;
      start *= 10;
      d++;
    }
    return ans;
  };

  i64 left = 1, right = 1e18;
  while (left <= right) {
    i64 mid = (left + right) / 2;
    i64 diff = calc(mid + n - 1) - calc(mid - 1);
    if (diff >= k) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  if (calc(left + n - 1) - calc(left - 1) == k) {
    cout << left << "\n";
  } else {
    cout << -1 << "\n";
  }
  return 0;
}
