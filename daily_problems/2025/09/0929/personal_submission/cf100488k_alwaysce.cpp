#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<i64> items(n);
  for (int i = 0; i < n; ++i) {
    cin >> items[i];
  }

  /*
    Alice和Bob轮流拿物品
    Alice可以任意挑剩下物品 Bob总是从开头第一个进行拿

    问最终Alice能获得的最大价值

    -> 前2k-1长度的子序列中最多取k个
    -> 开头相邻的物品只能取一个
  */

  i64 take = 0, tot = 0;
  priority_queue<i64, vector<i64>, greater<i64>> pq;
  for (int i = 0; i < n; i++) {
    int cur_id = i / 2 + 1;
    // 为什么这里的cur_id保证了开头相邻的物品只能取一个？
    // 因为相邻的物品i和i+1的cur_id是一样的
    // 只能取一个
    if (cur_id > pq.size()) {
      take += items[i];
      pq.push(items[i]);
    } else if (pq.top() < items[i]) {
      // 这里相当于在一个合法的序列上进行一次反悔操作
      take += items[i] - pq.top();
      pq.pop();
      pq.push(items[i]);
    }
    tot += items[i];
  }

  cout << take << ' ' << tot - take << '\n';

  return 0;
}
