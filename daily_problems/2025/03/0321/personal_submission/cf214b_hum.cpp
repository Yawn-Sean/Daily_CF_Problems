#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> cnt(10);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    cnt[x] += 1;
  }
  if (!cnt[0]) {
    cout << "-1\n";
    return 0;
  }

  string res = "0";
  cnt[0] -= 1;
  int tot = 0;
  for (int i = 0; i < 10; ++i) {
    tot += cnt[i] * i % 3;
  }
  tot %= 3;

  auto dec = [&](int r) {
    while (r < 10 && cnt[r] == 0) {
      r += 3;
    }
    if (r >= 10) {
      return -1;
    }
    cnt[r] -= 1;
    return r;
  };

  if (tot == 0) {
    for (int i = 0; i < 10; ++i) {
      res += string(cnt[i], '0' + i);
    }
  } else {
    if (dec(tot) == -1) {
      if (dec(3 - tot) == -1) {
        cout << "-1\n";
      }
      if (dec(3 - tot) == -1) {
        cout << "-1\n";
      }
    }
    for (int i = 0; i < 10; ++i) {
      res += string(cnt[i], '0' + i);
    }
  }
  while ((int) res.size() > 1 && res.back() == '0') {
    res.pop_back();
  }
  ranges::reverse(res);
  cout << res << "\n";
}
