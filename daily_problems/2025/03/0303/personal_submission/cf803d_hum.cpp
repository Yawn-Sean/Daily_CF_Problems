#include <bits/stdc++.h>
using namespace std;

int main() {
  int k;
  cin >> k;
  string s;
  getline(cin, s);
  getline(cin, s);
  vector<int> a;
  int cnt{};
  for (char c: s) {
    if (c == ' ' || c == '-') {
      a.push_back(cnt + 1);
      cnt = 0;
    } else {
      cnt++;
    }
  }
  a.push_back(cnt);
  auto check = [&](int x) {
    int tot{};
    for (int i = 0; i < a.size();) {
      int j = i - 1;
      int sum{};
      while (j + 1 < a.size() && sum + a[j + 1] <= x) {
        sum += a[++j];
      }
      if (j == i - 1) {
        return false;
      }
      tot++;
      i = j + 1;
    }
    return tot <= k;
  };
  int l{1}, r = s.size();
  while (l < r) {
    int mid = l + r >> 1;
    if (check(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << l << endl;
}
