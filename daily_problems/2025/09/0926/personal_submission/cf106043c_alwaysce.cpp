#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  // 单调栈维护一个元素作为最大值可以出现在哪些子数组内部
  // 长度为K的子数组最大值 集合的MEX是什么呢
  vector<int> left(n), right(n);
  {
    stack<int> stk;
    for (int i = 0; i < n; i++) {
      while (!stk.empty() && arr[stk.top()] < arr[i]) {
        stk.pop();
      }
      left[i] = stk.empty() ? -1 : stk.top();
      stk.push(i);
    }
  }
  {
    stack<int> stk;
    for (int i = n - 1; i >= 0; i--) {
      while (!stk.empty() && arr[stk.top()] <= arr[i]) {
        stk.pop();
      }
      right[i] = stk.empty() ? n : stk.top();
      stk.push(i);
    }
  }

  // 最大值=x可以出现在长度为1,2,...,right[i]-left[i]-1的子数组中
  // 那么怎么直到某一个长度=k的子数组的所有值的MEX呢
  // 假设这个值是v 那么0..v-1都能出现过
  // 相当于对于0-v-1所有数字 它的最大长度>=k
  // 维护0-i的最大值出现长度的最小值
  vector<int> maxLen(n + 1, 0), ans(n + 1, 0);
  for (int i = 0; i < n; i++) {
    if (arr[i] < n) {
      maxLen[arr[i]] = max(maxLen[arr[i]], right[i] - left[i] - 1);
    }
  }

  for (int i = 1; i <= n; i++) {
    maxLen[i] = min(maxLen[i], maxLen[i - 1]);
  }

  // 最小值改变的位置就是MEX数值变化的位置
  for (int i = 0; i <= n; i++) {
    ans[maxLen[i]] = i + 1;
  }

  // 变换前的数值
  for (int i = n - 1; i >= 0; i--) {
    ans[i] = max(ans[i], ans[i + 1]);
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
  }
  cout << endl;

  return 0;
}
