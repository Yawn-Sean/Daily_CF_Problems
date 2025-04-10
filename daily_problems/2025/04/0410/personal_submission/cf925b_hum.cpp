#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);


  int n, x1, x2;
  cin >> n >> x1 >> x2;

  vector<int> nums(n), order(n);
  for (auto &v: nums) cin >> v;

  iota(order.begin(), order.end(), 0);
  ranges::sort(order, [&](int i, int j) { return nums[i] < nums[j]; });

  for (int i = 0; i < n; i++) {
    int c1 = (x1 + nums[order[i]] - 1) / nums[order[i]];
    if (i + c1 < n && 1ll * nums[order[i + c1]] * (n - i - c1) >= x2) {
      cout << "Yes\n";
      cout << c1 << ' ' << n - i - c1 << '\n';
      for (int idx = i; idx < i + c1; idx++) cout << order[idx] + 1 << ' ';
      cout << '\n';
      for (int idx = i + c1; idx < n; idx++) cout << order[idx] + 1 << ' ';
      cout << '\n';
      return 0;
    }

    int c2 = (x2 + nums[order[i]] - 1) / nums[order[i]];
    if (i + c2 < n && 1ll * nums[order[i + c2]] * (n - i - c2) >= x1) {
      cout << "Yes\n";
      cout << n - i - c2 << ' ' << c2 << '\n';
      for (int idx = i + c2; idx < n; idx++) cout << order[idx] + 1 << ' ';
      cout << '\n';
      for (int idx = i; idx < i + c2; idx++) cout << order[idx] + 1 << ' ';
      cout << '\n';
      return 0;
    }
  }
  cout << "No\n";
}
