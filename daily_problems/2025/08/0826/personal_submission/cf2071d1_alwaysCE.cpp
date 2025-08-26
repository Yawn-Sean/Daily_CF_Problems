#include <bits/stdc++.h>
using namespace std;
using i64 = long long;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  vector<int> tmp;
  int t;
  cin >> t;
  while (t--) {
    i64 n, l, r;
    cin >> n >> l >> r;
    vector<int> nums(n);
    vector<int> pre(n + 1);
    for (int i = 0; i < n; i++) {
      cin >> nums[i];
      pre[i + 1] = pre[i] ^ nums[i];
    }

    map<i64, int> mp;
    function<int(i64)> preXor;
    function<int(i64)> get_answer;

    auto H_func = [&](i64 k) {
      if (k == 0) return 0;
      return (k % 2 == 0) ? preXor(k / 2) : 0;
    };

    preXor = [&](i64 k) {
      if (k == 0) return 0;
      if (mp.count(k)) {
        return mp[k];
      }
      if (k <= n) {
        return mp[k] = pre[k];
      }

      int H_k = H_func(k);
      int H_n = H_func(n);

      int sum_n1_k = H_k ^ H_n;
      return mp[k] = pre[n] ^ sum_n1_k;
    };

    get_answer = [&](i64 index) {
      if (index <= 0) {
        return 0;
      }
      if (index <= n) {
        return nums[index - 1];
      }
      return preXor(index / 2);
    };

    cout << get_answer(l) << endl;
  }
  return 0;
}
