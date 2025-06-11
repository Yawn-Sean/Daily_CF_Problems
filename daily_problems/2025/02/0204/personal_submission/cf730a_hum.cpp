#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<array<int, 2>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i][0];
    a[i][1] = i;
  }

  vector<string> res;
  ranges::sort(a, greater());

  while (a[0][0] != a[n - 1][0]) {
    int j = 0;
    while (j + 1 < n && a[j][0] == a[j + 1][0]) {
      j++;
    }
    int s = 0;
    if (j >= 1) {
      if (j % 2) {
        s = 2;
        a[0][0] = max(a[0][0] - 1, 0), a[1][0] = max(a[1][0] - 1, 0);
        string tmp(n, '0');
        tmp[a[0][1]] = tmp[a[1][1]] = '1';
        res.push_back(tmp);
      } else {
        s = 3;
        a[0][0] = max(a[0][0] - 1, 0), a[1][0] = max(a[1][0] - 1, 0), a[2][0] = max(a[2][0] - 1, 0);
        string tmp(n, '0');
        tmp[a[0][1]] = tmp[a[1][1]] = tmp[a[2][1]] = '1';
        res.push_back(tmp);
      }
    }
    for (int i = s; i <= j; i += 2) {
      a[i][0] = max(a[i][0] - 1, 0);
      a[i + 1][0] = max(a[i + 1][0] - 1, 0);
      string tmp(n, '0');
      tmp[a[i][1]] = tmp[a[i + 1][1]] = '1';
      res.push_back(tmp);
    }
    ranges::sort(a, greater());
  }
  cout << a[0][0] << endl;
  cout << res.size() << '\n';
  for (auto &s: res) {
    cout << s << '\n';
  }
}
