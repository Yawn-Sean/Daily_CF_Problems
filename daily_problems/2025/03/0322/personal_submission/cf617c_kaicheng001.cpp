// date: 2025/03/23
// author: kaicheng001
// problem: 617C - Watering Flowers
// URL: https://codeforces.com/problemset/problem/617/C

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  ll x1, y1, x2, y2;
  cin >> n >> x1 >> y1 >> x2 >> y2;

  vector<pair<ll, ll>> flowers(n);
  vector<ll> dist1(n), dist2(n);

  for (int i = 0; i < n; i++)
  {
    cin >> flowers[i].first >> flowers[i].second;
    dist1[i] = (flowers[i].first - x1) * (flowers[i].first - x1) +
               (flowers[i].second - y1) * (flowers[i].second - y1);
    dist2[i] = (flowers[i].first - x2) * (flowers[i].first - x2) +
               (flowers[i].second - y2) * (flowers[i].second - y2);
  }

  // 获取所有可能的距离值并排序
  vector<ll> possible_values;
  for (int i = 0; i < n; i++)
  {
    possible_values.push_back(dist1[i]);
    possible_values.push_back(dist2[i]);
  }
  possible_values.push_back(0); // 添加0作为可能值

  sort(possible_values.begin(), possible_values.end());
  possible_values.erase(unique(possible_values.begin(), possible_values.end()), possible_values.end());

  ll result = LLONG_MAX;

  // 对于每个可能的r1值，二分查找最小的r2值
  for (ll r1_sq : possible_values)
  {
    // 找出所有不被喷泉1覆盖的花
    vector<int> uncovered;
    for (int i = 0; i < n; i++)
    {
      if (dist1[i] > r1_sq)
      {
        uncovered.push_back(i);
      }
    }

    // 如果所有花都被喷泉1覆盖，r2可以是0
    if (uncovered.empty())
    {
      result = min(result, r1_sq);
      continue;
    }

    // 找到覆盖所有未覆盖花的最小r2值
    ll min_r2_sq = 0;
    for (int idx : uncovered)
    {
      min_r2_sq = max(min_r2_sq, dist2[idx]);
    }

    result = min(result, r1_sq + min_r2_sq);
  }

  cout << result << endl;
  return 0;
}