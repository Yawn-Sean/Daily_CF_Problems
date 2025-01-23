#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int m = ranges::max(a);
  vector<int> cnt(m + 2);
  for (int x: a) {
    cnt[x]++;
  }

  int l{}, sum{};
  array res{-1, -1, -1};
  for (int i = 0; i <= m + 1; i++) {
    if (l && cnt[i] < 2) {
      sum += cnt[i];
      if (sum > res[0]) {
        res = {sum, l, i};
      }
      l = 0;
      sum = 0;
    } else if (l && cnt[i] >= 2) {
      sum += cnt[i];
    }
    if (!l && cnt[i]) {
      l = i;
      sum += cnt[i];
    }
  }

  cout << res[0] << endl;
  for (int i = res[1]; i <= res[2]; i++) {
    for (int j = 0; j < cnt[i] - 1; j++) {
      cout << i << " ";
    }
  }
  for (int i = res[2]; i >= res[1]; --i) {
    if (cnt[i]) {
      cout << i << " ";
    }
  }
}
