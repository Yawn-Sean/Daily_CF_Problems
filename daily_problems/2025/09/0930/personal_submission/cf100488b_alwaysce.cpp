#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

set<int> query(int l, int r) {
  cout << "Q " << l << ' ' << r << endl;
  set<int> st;
  for (int i = l; i <= r; i++) {
    int x;
    cin >> x;
    st.insert(x);
  }
  return st;
}

void answer(const vector<int>& ans) {
  cout << "A ";
  for (int x : ans) {
    cout << x << ' ';
  }
  cout << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  // [1, n/2], [2, n/2+1], ..., [n/2, n-1]
  vector<int> ans(n);
  set<int> missing;
  for (int i = 1; i <= n; i++) {
    missing.insert(i);
  }

  if (n % 2 == 1) {
    set<int> res = query(n, n);
    ans[n - 1] = *res.begin();
    missing.erase(ans[n - 1]);
    n -= 1;
  }

  if (n > 1) {
    set<int> lhs = query(1, n / 2); // [1, n/2]
    set<int> rhs; // [n/2+1,n]

    for (auto& v: missing) {
      if (!lhs.count(v)) {
        rhs.insert(v);
      }
    }

    // [2,3,..,n/2-1], [n/2+1,...,n-1]
    for (int i = 2; i <= n / 2; i++) {
      auto mid = query(i, n + 1 - i);
      for (auto& v: lhs) {
        if (!mid.count(v)) {
          lhs.erase(v);
          ans[i - 2] = v;
          break;
        }
      }

      for (auto& v: rhs) {
        if (!mid.count(v)) {
          rhs.erase(v);
          ans[n - i + 1] = v;
          break;
        }
      }
    }

    ans[n / 2 - 1] = *lhs.begin();
    ans[n / 2] = *rhs.begin();
  }

  answer(ans);
  return 0;
}
