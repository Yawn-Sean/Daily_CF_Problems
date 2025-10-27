#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int MX = 1e6;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  i64 n, k;
  cin >> n >> k;

  if (k > n * (n - 1) / 2) {
    cout << -1 << endl;
    return 0;
  }

  vector<i64> ans;
  for (i64 p = 1; p <= n; p++) {
    if (p * (p + 1) / 2 > k) {
      for (int i = 1; i <= p; i++) {
        ans.push_back(2);
      }
      k -= (p - 1) * p / 2;
      for (int i = 0; i < k; i++) {
        ans[i] = 6;
      }
      if (k > 0) {
        ans.push_back(3);
        k--;
      }
      break;
    }
  }

  // 两两互质的6k+1,6k+5
  // 怎么构造? 太小了就会有(25,35)这种pair
  // 这里感觉很神奇 前面的 p <= sqrt(1e5)
  // 所以可能后面要增加9e4个数
  for (int i = 999997; i >= 0; i -= 6) {
    if (ans.size() < n) {
      ans.push_back(i);
    }
    if (ans.size() < n) {
      ans.push_back(i - 2);
    }
    if (ans.size() >= n) {
      break;
    }
  }

  for (auto x : ans) {
    cout << x << " ";
  }
  cout << endl;

  return 0;
}
