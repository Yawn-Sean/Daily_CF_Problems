// Author: zengyz
// 2025-06-12 15:55

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
using i64 = long long;

void solve()
{
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n, 0));
  vector<pair<int, int>> vp[10];

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      char op;
      cin >> op;
      a[i][j] =op-'0';
      vp[a[i][j]].push_back({i, j});
    }
  }

  for (int i = 0; i <= 9; i++)
  {
    if (vp[i].size() <= 1)
    {
      cout << "0 " ;
    }
    else
    {
      int ans=0;
      for(int k=0;k<2;k++)
      {
        sort(vp[i].begin(), vp[i].end());
        for(auto x:vp[i])
        {
          int disx=max(vp[i].back().first-x.first,x.first-vp[i][0].first);
          int disy=max(x.second,n-1-x.second);
          ans=max(ans,disx*disy);
        }
        for(auto &x:vp[i])
        swap(x.first,x.second);
      }
      cout<<ans<<" ";
    }
  }
  cout<<endl;
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