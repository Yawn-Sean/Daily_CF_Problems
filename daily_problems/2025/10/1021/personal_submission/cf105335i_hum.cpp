#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> nums(n);
  for (auto &v: nums) cin >> v;

  vector<long long> tmp = {nums[0] - 1, nums[1] - 1};
  if (tmp[1] > tmp[0]) tmp[1]--;

  tmp[1] += 1ll * n * (n - 1) / 2;
  tmp[0] += tmp[1] / (n - 1);
  tmp[1] %= n - 1;
  tmp[0] %= n;

  vector<int> ans = {tmp[0] + 1, tmp[1] + 1};
  if (ans[1] >= ans[0]) ans[1]++;

  vector<int> vis1(n + 1, 0), vis2(n + 1, 1);

  for (int i = 2; i < n; i++)
    vis1[nums[i]] = 1;

  for (auto &x: ans)
    vis2[x] = 0;

  vector<int> mapping(n + 1, 0);
  int p1 = 1, p2 = 1;

  for (int _ = 0; _ < n - 2; _++) {
    while (!vis1[p1]) p1++;
    while (!vis2[p2]) p2++;
    mapping[p1++] = p2++;
  }

  for (int i = 2; i < n; i++)
    ans.emplace_back(mapping[nums[i]]);

  for (auto &x: ans) cout << x << ' ';
}
