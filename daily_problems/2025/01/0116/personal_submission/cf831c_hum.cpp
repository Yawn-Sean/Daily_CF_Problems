#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i) a[i] += a[i - 1];
  }
  vector<int> b(k);
  for (int i = 0; i < k; i++) {
    cin >> b[i];
  }
  set s(a.begin(), a.end());
  int res = 0;
  for (int x: s) {
    int v = b[0] - x;
    int t = 1;
    for (int i = 1; i < k; i++) {
      if (s.find(b[i] - v) == s.end()) {
        t = 0;
        break;
      }
    }
    res += t;
  }
  cout << res << endl;
}
