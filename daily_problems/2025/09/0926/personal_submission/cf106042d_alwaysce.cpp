#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }

    // A[i] | x
    // A[i] & y
    //|x一定会至少是的A[i]的值 >=
    // Alice为了让最终分值最小应该选择 |x后值最小的数
    // Bob为了让最终分值最大应该选择 &y后值最大的数
    // 两种情况: Alice和Bob选了同一个数
    // 或者选了不同的数
    i64 S = accumulate(arr.begin(), arr.end(), 0LL);

    // 预处理 d[j] = (A[j]&y) - A[j] 的最大值和次大值
    vector<i64> d(n);
    i64 best1 = LLONG_MIN, best2 = LLONG_MIN;
    int id1 = -1, id2 = -1;
    for (int j = 0; j < n; j++) {
      d[j] = 1ll * ((arr[j]) & y) - arr[j];
      if (d[j] > best1) {
        best2 = best1;
        id2 = id1;
        best1 = d[j];
        id1 = j;
      } else if (d[j] > best2) {
        best2 = d[j];
        id2 = j;
      }
    }

    i64 ans = LLONG_MAX;
    for (int i = 0; i < n; i++) {
      // Bob 选同一个下标
      i64 delta_same = ((arr[i] | x) & y) - arr[i];
      // Bob 选不同下标
      i64 best_diff_bob = (id1 != i ? best1 : best2);
      i64 delta_diff =
          (n >= 2 ? ((arr[i] | x) - arr[i] + best_diff_bob) : LLONG_MIN / 4);

      // Bob 在两种里取较大，Alice 取使总和最小的 i
      i64 total = S + max(delta_same, delta_diff);
      ans = min(ans, total);
    }

    cout << ans << "\n";
  }
  return 0;
}
