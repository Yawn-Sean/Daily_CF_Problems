// Author: zengyz
// 2025-06-12 18:15

#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
const int N = 2e5 + 10;
int tr[2][2][N * 4], val[N * 4];
int a[N];
void pushup(int u)
{
  tr[0][0][u] = min(tr[0][0][u << 1], tr[0][0][u << 1 | 1]);
  tr[0][1][u] = max(tr[0][1][u << 1], tr[0][1][u << 1 | 1]);
  tr[1][0][u] = min(tr[1][0][u << 1], tr[1][0][u << 1 | 1]);
  tr[1][1][u] = max(tr[1][1][u << 1], tr[1][1][u << 1 | 1]);

  val[u] = max(tr[0][1][u << 1] - tr[0][0][u << 1 | 1], tr[1][1][u << 1 | 1] - tr[1][0][u << 1]);
  val[u] = max(val[u], max(val[u << 1], val[u << 1 | 1]));
}
void build(int u, int l, int r)
{
  if (l == r)
  {
    tr[0][0][u] = tr[0][1][u] = a[l] + l;
    tr[1][0][u] = tr[1][1][u] = a[l] - l;
    val[u] = 0;
    return;
  }
  else
  {
    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
  }
}
void modify(int u, int l, int r, int p, int x)
{
  if (l == r)
  {
    tr[0][0][u] = tr[0][1][u] = x + p;
    tr[1][0][u] = tr[1][1][u] = x - p;
    return;
  }
  int mid = (l + r) >> 1;
  if (p <= mid)
    modify(u << 1, l, mid, p, x);
  else
    modify(u << 1 | 1, mid + 1, r, p, x);
  pushup(u);
}

void solve()
{
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  build(1, 1, n);
  cout << val[1] << endl;
  while (q--)
  {
    int p, x;
    cin >> p >> x;
    a[p] = x;
    modify(1, 1, n, p, x);
    cout << val[1] << endl;
  }

  return;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int _T = 1;
  cin >> _T;
  while (_T--)
  {
    solve();
  }
  return 0;
}