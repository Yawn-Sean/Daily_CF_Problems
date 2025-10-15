#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    long long k;
    cin >> k;

    vector<int> a;
    map<int, int> cnt;
    int idx{2};
    while (k) {
      a.push_back(k % idx);
      cnt[k % idx]++;
      k = k / idx;
      idx++;
    }
    ranges::sort(a, greater());
    auto f = [&]() {
      int n = a.size();
      long long res{1};
      for (int i = 0; i < n; i++) {
        res *= min(n, n + 1 - a[i]) - i;
      }
      for (auto [_, c]: cnt) {
        for (int i = 2; i <= c; i++) {
          res /= i;
        }
      }
      return res;
    };
    long long res = f();

    if (a.back() == 0) {
      a.pop_back();
      cnt[0]--;
      res -= f();
    }
    cout << --res << '\n';
  }
}
