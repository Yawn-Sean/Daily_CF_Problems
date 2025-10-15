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

  int n;
  cin >> n;

  priority_queue<int, vector<int>, greater<>> pq;
  vector<pair<int, int>> res;

  while (n--) {
    string s;
    cin >> s;

    if (s[0] == 'i') {
      int x;
      cin >> x;
      pq.push(x);
      res.emplace_back(0, x);
    } else if (s[0] == 'g') {
      int x;
      cin >> x;

      while (!pq.empty() && pq.top() < x) {
        pq.pop();
        res.emplace_back(2, 0);
      }

      if (pq.empty() || pq.top() != x) {
        pq.push(x);
        res.emplace_back(0, x);
      }

      res.emplace_back(1, x);
    } else {
      if (pq.empty()) {
        pq.push(1);
        res.emplace_back(0, 1);
      }

      pq.pop();
      res.emplace_back(2, 0);
    }
  }

  cout << res.size() << '\n';
  for (auto &[x, y]: res) {
    if (x == 0) cout << "insert " << y << '\n';
    else if (x == 1) cout << "getMin " << y << '\n';
    else cout << "removeMin\n";
  }
}
