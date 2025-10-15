#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1000000007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> xs(n), ys(n), vs(n);
  for (int i = 0; i < n; i++) {
    cin >> xs[i] >> ys[i] >> vs[i];
  }

  int MX = 1e6;

  auto solve = [&]() {
    vector<int> cnt(MX + 1);
    for (int i = 0; i < n; i++) {
      cnt[ys[i]] += vs[i];
    }

    vector<int> order(MX + 1);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(),
         [&](int a, int b) { return cnt[a] > cnt[b]; });

    i64 ans = cnt[order[0]] + cnt[order[1]] + cnt[order[2]];

    map<int, vector<int>> mp;

    for (int i = 0; i < n; i++) {
      mp[xs[i]].push_back(i);
    }

    for (auto& [k, v] : mp) {
      i64 cur = 0;
      for (auto& idx : v) {
        cur += vs[idx];
        cnt[ys[idx]] -= vs[idx];
      }

      i64 v1 = 0, v2 = 0;
      // 因为选1个x最多影响两个y 所以只需要到前v+2个order里面进行遍历就够了
      for (int i = 0; i < (int)v.size() + 2; i++) {
        i64 val = cnt[order[i]];
        if (val > v1) {
          swap(v1, v2);
          v1 = val;
        } else if (val > v2) {
          v2 = val;
        }
      }
      ans = max(ans, cur + v1 + v2);

      for (auto& idx : v) {
        cnt[ys[idx]] += vs[idx];
      }
    }

    return ans;
  };

  i64 ans = solve();
  for (int i = 0; i < n; i++) {
    swap(xs[i], ys[i]);
  }
  ans = max(ans, solve());
  cout << ans << endl;

  return 0;
}
