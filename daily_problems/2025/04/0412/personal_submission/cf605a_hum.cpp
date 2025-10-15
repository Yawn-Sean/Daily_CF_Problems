#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<int> b(n + 1);
  int res{n};
  for (int i = 0; i < n; ++i) {
    b[a[i]] = b[a[i] - 1] + 1;
    res = min(res, n - b[a[i]]);
  }
  cout << res << endl;
}
