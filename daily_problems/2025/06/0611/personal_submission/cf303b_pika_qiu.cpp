// Author: zengyz
// 2025-06-11 09:11

#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int gcd(int a, int b)
{
  return b ? gcd(b, a % b) : a;
}
void solve()
{
  int n, m, x, y, a, b;
  cin >> n >> m >> x >> y >> a >> b;
  int g = gcd(a, b);
  a /= g;
  b /= g;
  int t = min(n / a, m / b);
  int n1 = a * t, m1 = b * t;
  int x0 = min(n - n1, max(0, x - (n1 + 1) / 2));
  int y0 = min(m - m1, max(0, y - (m1 + 1) / 2));
  cout<<x0<<" "<<y0<<" "<<x0+n1<<" "<<y0+m1<<endl;
  return;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int _T = 1;
  // cin >> _T;
  while (_T--)
  {
    solve();
  }
  return 0;
}