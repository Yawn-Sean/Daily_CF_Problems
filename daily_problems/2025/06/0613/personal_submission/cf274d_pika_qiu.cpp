// Author: zengyz
// 2025-06-13 18:02

#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
const int N = 1e5 + 10;
pair<int, int> p[N];
// int a[N], p[N];
vector<int> edge[N * 3], ans;
int n, m;
int cnt[N * 3];
queue<int> q;
bool TopSort(int n)
{
  for (int i = 1; i <= n; i++)
    if (cnt[i] == 0)
      q.push(i);
  for (int i = 1; i <= n; i++)
  {
    if (q.size() == 0)
      return 0;
    int idx = q.front();
    q.pop();
    ans.push_back(idx);
    for (int j = 0; j < edge[idx].size(); j++)
      if ((--cnt[edge[idx][j]]) == 0)
        q.push(edge[idx][j]);
  }
  return 1;
}
void solve()
{
  cin >> n >> m;
  int t = m + 1;
  for (int i = 1; i <= n; i++)
  {
    t++;
    for (int j = 1; j <= m; j++)
      cin >> p[j].first, p[j].second = j;
    sort(p + 1, p + 1 + m);
    int k = 1;
    while (p[k].first == -1)
      k++;
    while (k <= m)
    {
      int j = k;
      while (j <= m && p[j].first == p[k].first)
      {
        edge[t].push_back(p[j].second), cnt[p[j].second]++;
        edge[p[j++].second].push_back(t + 1), cnt[t + 1]++;
      }
      k = j;
      t++;
    }
  }
  if (TopSort(t) == 0)
    cout << -1 << endl;
  else
    for (int i = 0; i < ans.size(); i++)
    {
      if (ans[i] <= m)
        cout << ans[i] << " ";
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