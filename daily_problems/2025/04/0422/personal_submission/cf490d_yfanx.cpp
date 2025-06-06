#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll vp(ll n, ll p) {
  ll cnt = 0;
  while (n % p == 0) {
    n /= p;
    ++cnt;
  }
  return cnt;
}

void op3(ll &x, ll &y) {
  if (x % 3 == 0)
    x = x / 3 * 2;
  else
    y = y / 3 * 2;
}

void op2(ll &x, ll &y) {
  if (x % 2 == 0)
    x /= 2;
  else
    y /= 2;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll a1, b1, a2, b2;
  cin >> a1 >> b1 >> a2 >> b2;

  ll e2_1 = vp(a1, 2) + vp(b1, 2);
  ll e3_1 = vp(a1, 3) + vp(b1, 3);
  ll e2_2 = vp(a2, 2) + vp(b2, 2);
  ll e3_2 = vp(a2, 3) + vp(b2, 3);

  ll ops = 0;

  while (e3_1 > e3_2) {
    op3(a1, b1);
    --e3_1;
    ++e2_1;
    ++ops;
  }

  while (e3_2 > e3_1) {
    op3(a2, b2);
    --e3_2;
    ++e2_2;
    ++ops;
  }

  while (e2_1 > e2_2) {
    op2(a1, b1);
    --e2_1;
    ++ops;
  }
  while (e2_2 > e2_1) {
    op2(a2, b2);
    --e2_2;
    ++ops;
  }

  if (a1 * b1 != a2 * b2) {
    cout << -1 << "\n";
    return 0;
  }

  cout << ops << "\n";
  cout << a1 << " " << b1 << "\n";
  cout << a2 << " " << b2 << "\n";
  return 0;
}
