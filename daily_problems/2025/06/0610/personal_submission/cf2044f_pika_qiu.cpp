// Author: zengyz
// 2025-06-10 15:19

#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve()
{
  i64 n, m, q;
  cin >> n >> m >> q;
  vector<i64> a(n), b(m);
  set<i64> s1, s2;
  i64 res1 = 0, res2 = 0;
  for (i64 i = 0; i < n; i++)
    cin >> a[i], res1 += a[i];
  for (auto x : a)
    s1.insert(res1 - x);

  for (i64 i = 0; i < m; i++)
    cin >> b[i], res2 += b[i];
  for (auto x : b)
    s2.insert(res2 - x);
  while (q--)
  {
    i64 target;
    cin >> target;
    bool flag = false;
    for (i64 i = 1; i <= abs(target) / i; i++)
    {
      if (target % i == 0)
      {
        if (s1.count(i) && s2.count(target / i))
          flag = true;
        if (s1.count(-i) && s2.count(-target / i))
          flag = true;
        if (s2.count(-i) && s1.count(-target / i))
          flag = true;
        if (s2.count(i) && s1.count(target / i))
          flag = true;
      }
    }
    if (flag)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
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