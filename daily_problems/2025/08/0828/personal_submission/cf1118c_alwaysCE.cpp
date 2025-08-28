#include <bits/stdc++.h>
using namespace std;
using i64 = long long;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  vector<int> cnt(1001);
  vector<int> nums(n * n);
  for (int i = 0; i < n * n; i++) {
    cin >> nums[i];
    ++cnt[nums[i]];
  }

  vector<vector<int>> ans(n, vector<int>(n, -1));
  for (int i = 0; i < n / 2; i++) {
    for (int j = 0; j < n / 2; j++) {
      bool put = false;
      for (int num = 1; num <= 1000 && !put; num++) {
        if (cnt[num] >= 4) {
          put = true;
          ans[i][j] = num;
          ans[n - 1 - i][j] = num;
          ans[n - 1 - i][n - 1 - j] = num;
          ans[i][n - 1 - j] = num;
          cnt[num] -= 4;
          break;
        }
      }
      if (!put) {
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  if (n % 2) {
    for (int i = 0; i < n / 2; i++) {
      bool put = false;
      for (int num = 1; num <= 1000; num++) {
        if (cnt[num] >= 2) {
          ans[i][n / 2] = num;
          ans[n - 1 - i][n / 2] = num;
          cnt[num] -= 2;
          put = true;
          break;
        }
      }
      if (!put) {
        cout << "NO" << endl;
        return 0;
      }
    }
    for (int i = 0; i < n / 2; i++) {
      bool put = false;
      for (int num = 1; num <= 1000; num++) {
        if (cnt[num] >= 2) {
          ans[n / 2][i] = num;
          ans[n / 2][n - 1 - i] = num;
          cnt[num] -= 2;
          put = true;
          break;
        }
      }
      if (!put) {
        cout << "NO" << endl;
        return 0;
      }
    }
    bool put = false;
    for (int num = 1; num <= 1000; num++) {
      if (cnt[num] >= 1) {
        ans[n / 2][n / 2] = num;
        cnt[num] -= 1;
        put = true;
        break;
      }
    }
    if (!put) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
