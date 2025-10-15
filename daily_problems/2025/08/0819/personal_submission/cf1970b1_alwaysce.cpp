#include <algorithm>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::ios_base;
using std::vector;
using i64 = int64_t;
using std::sort;
using std::iota;

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
  vector<int> order(n);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int i, int j) {
    return nums[i] < nums[j];
  });

  vector<int> ans(n);
  bool flag = true;
  for (int i = 0; i < n; i++) {
    int idx = order[i];
    int d = nums[idx] / 2;
    int t1 = idx - d;
    int t2 = idx + d;
    bool found = false;
    if (t1 >= 0 && t1 < n) {
      ans[idx] = t1;
      found = true;
    } else if (t2 >= 0 && t2 < n) {
      ans[idx] = t2;
      found = true;
    }
    if (!found) {
      flag = false;
      break;
    }
  }
  if (flag) {
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
      cout << i + 1 << ' ' << i + 1 << endl;
    }
    for (int i = 0; i < n; i++) {
      cout << ans[i] + 1 << " ";
    }
    cout << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
