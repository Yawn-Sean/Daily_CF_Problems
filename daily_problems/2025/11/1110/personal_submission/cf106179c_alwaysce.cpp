#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    i64 c;
    cin >> c;

    int h = 63 - __builtin_clzll(c);
    i64 shift = h + 1;
    i64 a = c << shift;
    i64 b = c;
    cout << a << " " << b << "\n";
  }
  return 0;
}
