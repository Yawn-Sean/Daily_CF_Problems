#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int x2;
  cin >> x2;
  vector<int> a(x2 + 1);
  for (int i = 2; i <= x2; i++) {
    if (a[i] == 0) {
      for (int j = i; j <= x2; j += i) {
        a[j] = i;
      }
    }
  }
  int res{x2};
  for (int i = x2 - a[x2] + 1; i <= x2; i++) {
    if (a[i] != i) {
      res = min(res, i - a[i] + 1);
    }
  }
  cout << res << endl;
}
