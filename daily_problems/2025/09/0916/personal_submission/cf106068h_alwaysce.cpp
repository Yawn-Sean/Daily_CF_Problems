#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 MOD = 998244353;

/*
  给你一个由 N 个整数组成的数组 A
 。此外，你还得到了 Q
 个查询，其中有两种查询类型：

更新查询：'1 i val' 将位置 i 的元素更新为 val; Ai← val

查找查询：'2 i' 查找数组中任意位置 j 中的 |(i−j)^3|≥Aj 元素。

对于查找查询，如果存在这样的位置 j ，则打印任何有效的 j。
 如果不存在这样的位置，则打印 -1。
*/
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int N;
  cin >> N;
  vector<i64> A(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }

  int Q;
  cin >> Q;
  for (int i = 0; i < Q; i++) {
    int op;
    cin >> op;
    if (op == 1) {
      int idx;
      i64 val;
      cin >> idx >> val;
      A[idx] = val;
    } else {
      int idx;
      cin >> idx;
      if (N >= 2000) {
        int idx1 = idx - 1000;
        int idx2 = idx + 1000;
        if (idx1 >= 1) {
          cout << idx1 << "\n";
        } else {
          cout << idx2 << "\n";
        }
      } else {
        bool found = false;
        for (int j = 1; j <= N; j++) {
          if (j != idx) {
            i64 dist = abs(i64(idx - j));
            i64 dist_cubed = dist * dist * dist;
            if (dist_cubed >= A[j]) {
              cout << j << "\n";
              found = true;
              break;
            }
          }
        }
        if (!found) {
          cout << -1 << "\n";
        }
      }
    }
  }
  return 0;
}
