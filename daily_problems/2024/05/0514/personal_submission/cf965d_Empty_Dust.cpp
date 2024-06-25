#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], f[MAXN], n;
using pt = std::pair<int, int>;

signed main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0), std::cout.tie(0);
  int w, l;
  std::cin >> w >> l;
  for (int i = 1; i <= w - 1; ++i)
    std::cin >> nums[i];
  f[0] = nums[w] = 1e9;
  std::deque<pt> q;
  for (int i = 0, r = l, x = 1; i <= w - 1; ++i, ++r)
  {
    while (x <= w && x <= r)
    {
      q.push_back({nums[x], x});
      x++;
    }
    while (q.size() && q.front().second <= i)
      q.pop_front();
    while (q.size() && f[i])
    {
      if (f[i] > q.back().first)
      {
        f[i] -= q.back().first;
        f[q.back().second] += q.back().first;
        q.pop_back();
      }
      else
      {
        q.back().first -= f[i];
        f[q.back().second] += f[i];
        f[i] = 0;
      }
    }
    // for (int i = 1;i <= w;++i)std::cout << f[i] << ' ';
    // std::cout << '\n';
  }
  std::cout << f[w];
  return 0;
}