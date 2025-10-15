#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k, a, b, q;
  cin >> n >> k >> a >> b >> q;

  Fenwick<int> fen1(n), fen2(n);
  vector<int> vec(n);

  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int x, y;
      cin >> x >> y;
      vec[x - 1] += y;
      fen1.set(x - 1, min(vec[x - 1], b));
      fen2.set(x - 1, min(vec[x - 1], a));
    } else {
      int x;
      cin >> x;
      x--;
      cout << fen1.rangeSum(0, x) + fen2.rangeSum(x + k, n) << '\n';
    }
  }
}
