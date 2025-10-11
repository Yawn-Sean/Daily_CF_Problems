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

  int m = n;
  vector<int> ans;
  while (m > 0) {
    int pos = -1;
    for (int j = m - 1; j >= 0; j--) {
      if (nums[j] == j + 1) {
        pos = j;
        break;
      }
    }
    if (pos == -1) {
      cout << "NO\n";
      return 0;
    }
    nums.erase(nums.begin() + pos);
    m--;
    ans.push_back(pos + 1);
  }

  cout << "YES\n";
  for (int i = 0; i < n; i++) {
    cout << ans[n - 1 - i] << " ";
  }
  return 0;
}
