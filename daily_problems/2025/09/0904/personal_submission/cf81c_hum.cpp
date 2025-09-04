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

  int n, a, b;
  cin >> n >> a >> b;

  vector<int> nums(n);
  for (auto &v: nums) cin >> v;

  if (a == b) {
    while (a--) cout << "1 ";
    while (b--) cout << "2 ";
  } else {
    vector<int> idxs(n);
    iota(idxs.begin(), idxs.end(), 0);

    if (a < b) {
      ranges::stable_sort(idxs, [&](int i, int j) { return nums[i] > nums[j]; });
    } else {
      ranges::stable_sort(idxs, [&](int i, int j) { return nums[i] < nums[j]; });
    }
    vector res(n, 2);
    for (int i = 0; i < a; i++) {
      res[idxs[i]] = 1;
    }

    for (auto &v: res) {
      cout << v << ' ';
    }
  }
}
