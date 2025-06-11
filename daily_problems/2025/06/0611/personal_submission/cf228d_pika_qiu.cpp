// Author: zengyz
// 2025-06-11 16:44

#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
int n, m;
int lowbit(int x)
{
  return x & (-x);
}
const int N = 1e5 + 10;
i64 tr[7][10][N];
i64 a[N], b[N];
void add(i64 tr[], int pos, int v)
{
  for (; pos <= n; pos += lowbit(pos))
    tr[pos] += v;
}
i64 sum(i64 tr[], int pos)
{
  i64 v = 0;
  for (; pos>=1; pos -= lowbit(pos))
    v += tr[pos];
  return v;
}
void update(int pos, int v)
{
  for (int i = 2; i <= 6; i++)
  {
    add(tr[i][pos % (2 * (i - 1))], pos, v - a[pos]);
  }
  a[pos] = v;
}
i64 query(int l, int r, int z)
{
  i64 res = 0;
  for (int j = 0; j < 2 * (z - 1); j++)
  {
    i64 val = sum(tr[z][j], r) - sum(tr[z][j], l - 1);
    int mod = 2 * (z - 1);
    int p = (j - l % mod + 1 + mod) % mod;
    if(p==0)
    res+=2*val;
    else if(p<=z)
    res+=p*val;
    else
    res+=(2*z-p)*val;
  }
  return res;
}
void solve()
{
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> b[i];
  for (int i = 1; i <= n; i++)
    update(i, b[i]);
  cin >> m;
  while (m--)
  {
    int op;
    cin >> op;
    if (op == 1)
    {
      int p, v;
      cin >> p >> v;
      update(p, v);
    }
    else
    {
      int l, r, z;
      cin >> l >> r >> z;
      cout << query(l, r, z) << endl;
    }
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