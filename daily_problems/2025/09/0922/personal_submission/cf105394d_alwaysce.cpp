#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;

  cin >> n >> q;
  long double p;
  cin >> p;

  p *= 1000000;
  i64 pp = 1000000 - round(p);
  Z r = Z(pp) / Z(1000000);

  vector<Z> pow(n + 1), invPow(n + 1);
  pow[0] = 1;
  invPow[0] = 1;
  for (int i = 1; i <= n; i++) {
    pow[i] = pow[i - 1] * r;
    invPow[i] = invPow[i - 1] / r;
  }

  Fenwick<Z> preL(n + 1), sufR(n + 1);
  vector<Z> a(n);
  for (int i = 0; i < q; i++) {
    char op;
    cin >> op;
    i64 b, x;

    if (op == '+') {
      cin >> b >> x;
      --x;
      Z diff = Z(b);
      a[x] += diff;
      preL.add(x + 1, diff * invPow[x]); // a[b]*r^(-i)
      sufR.add(x + 1, diff * pow[x]); // a[b]*r^i
    } else if (op == '-') {
      cin >> b >> x;
      --x;
      Z diff = Z(b);
      a[x] -= diff;
      preL.add(x + 1, -diff * invPow[x]);
      sufR.add(x + 1, -diff * pow[x]);
    } else {
      cin >> x;
      --x;
      Z ans = pow[x] * preL.sum(x + 1); // sum_{i=0}^{b} a[i]*r^(b-i)
      ans += invPow[x] * sufR.rangeSum(x + 1 + 1, n); // sum_{i=b}^{n-1} a[i]*r^(i-b)
      cout << ans << endl;
    }
  }


  return 0;
}
