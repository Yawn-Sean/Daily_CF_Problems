#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int j{-1}, cnt{};
  array res{0,-1,-1};
  for (int i = 0; i < n; ++i) {
    while (j + 1 < n && cnt + (1 - a[j + 1]) <= k) {
      ++j;
      cnt += 1 - a[j];
    }
    if (j - i + 1 > res[0]) {
      res = {j - i + 1, i, j};
    }
    if (a[i] == 0) {
      cnt--;
    }
  }
  cout << res[0] << endl;
  for (int i = 0; i < n; ++i) {
    if (res[1] <= i && i <= res[2]) {
      cout << 1 << " ";
    } else {
      cout << a[i] << " ";
    }
  }
}
