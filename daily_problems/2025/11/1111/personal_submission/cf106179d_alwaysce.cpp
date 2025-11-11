#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
      cin >> p[i];
    }

    vector<int> left, right;
    for (int i = 0; i < n; i++) {
      if ((i < n / 2) != (p[i] <= n / 2)) {
        left.push_back(p[i]);
      } else {
        right.push_back(p[i]);
      }
    }

    if (!left.empty() && !right.empty()) {
      cout << 2 << "\n";
      cout << left.size() << ' ';
      for (int x : left) {
        cout << x << ' ';
      }
      cout << "\n";
      cout << right.size() << ' ';
      for (int x : right) {
        cout << x << ' ';
      }
      cout << "\n";
    } else {
      cout << 1 << "\n";
      cout << n << ' ';
      for (auto& x : p) {
        cout << x << ' ';
      }
      cout << "\n";
    }
  }
  return 0;
}
