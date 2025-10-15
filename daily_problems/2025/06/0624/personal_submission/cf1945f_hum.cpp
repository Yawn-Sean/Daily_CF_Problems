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
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n), p(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> p[i], p[i]--;
    priority_queue<int, vector<int>, greater<>> pq;
    long long res{};
    int k{};
    for (int i = n - 1; i >= 0; i--) {
      pq.push(a[p[i]]);
      while (pq.size() > i + 1) {
        pq.pop();
      }
      if (pq.size() == i + 1 && 1LL * (i + 1) * pq.top() >= res) {
        res = 1LL * (i + 1) * pq.top();
        k = i + 1;
      }
    }
    cout << res << ' ' << k << '\n';
  }
}
