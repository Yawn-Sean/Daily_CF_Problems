#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> prs = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
  vector<long long> to_check = {1};

  for (auto &x: prs) {
    int k = to_check.size();
    for (int i = 0; i < k; i++) {
      to_check.emplace_back(to_check[i] * x);
    }
  }
  ranges::sort(to_check);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> vis(51, 0);
    while (n--) {
      int x;
      cin >> x;
      vis[x] = 1;
    }

    for (auto &v: to_check) {
      bool flg = true;
      for (int i = 0; i <= 50; i++) {
        if (vis[i] && gcd(i, v) == 1) {
          flg = false;
          break;
        }
      }
      if (flg) {
        cout << v << '\n';
        break;
      }
    }
  }
}
