#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int m = ranges::max(a);
  bool f{false};
  for (int i = 0; i < n; i++) {
    if (m % a[i] != 0) {
      f = true;
      break;
    }
  }
  if (f) {
    cout << n << endl;
  } else {
    unordered_set<int> st;
    for (int x: a) {
      st.insert(x);
    }
    auto check = [&](int x) {
      int cnt{};
      int l{1};
      for (int i = 0; i < n; i++) {
        if (x % a[i] == 0) {
          cnt++;
          l = lcm(l, a[i]);
        }
      }
      if (l == x) {
        return cnt;
      }
      return 0;
    };
    int res{};
    for (int i = 2; i * i <= m; i++) {
      if (m % i == 0) {
        if (!st.contains(i)) {
          res = max(res, check(i));
        }
        if (!st.contains(m / i)) {
          res = max(res, check(m / i));
        }
      }
    }
    cout << res << endl;
  }
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
