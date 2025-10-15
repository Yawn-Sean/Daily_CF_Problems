#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::ios_base;
using std::vector;
using i64 = int64_t;
using std::sort;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  i64 k;
  cin >> n >> k;
  --k;
  vector<int> nums(n);
  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
  }
  sort(nums.begin(), nums.end());

  int i = 0, j = 0;
  while (i < n) {
    j = i;
    while (j < n && nums[j] == nums[i]) {
      ++j;
    }
    if (k < 1ll * (j - i) * n) {
      break;
    }
    k -= 1ll * (j - i) * n;
    i = j;
  }

  // starts with nums[i]
  cout << nums[i] << ' ' << nums[k / (j - i)] << endl;
  return 0;
}
