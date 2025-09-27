#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, m, q;
    cin >> n >> m >> q;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
      cin >> nums[i];
    }

    vector<int> cnt(m + 1, 0);
    for (int j = 0; j < n; j++) {
      cnt[nums[j]] ^= 1;
    }

    vector<int> next_odd(m + 1, 1e9);
    for (int i = 0; i <= m; i++) {
      if (cnt[i]) {
        next_odd[i] = 0;
      }
    }

    for (int i = m; i > 0; i--) {
      next_odd[i - 1] = min(next_odd[i - 1], next_odd[i] + 1);
    }
    next_odd[m] = min(next_odd[m], next_odd[0]);
    for (int i = m; i > 0; i--) {
      next_odd[i - 1] = min(next_odd[i - 1], next_odd[i] + 1);
    }

    int num_op = 0;
    for (int i = 0; i < q; i++) {
      int op;
      cin >> op;

      if (op == 1) {
        ++num_op;
      } else {
        int idx;
        cin >> idx;
        --idx;

        int x = nums[idx];
        int step = min(num_op, next_odd[x]);
        cout << (x + step - 1) % m + 1 << endl;
      }
    }
  }

  return 0;
}
