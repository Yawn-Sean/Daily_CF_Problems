#include <bits/stdc++.h>
using namespace std;
using i64 = long long;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  i64 a, b, w, x, c;
  cin >> a >> b >> w >> x >> c;

  cout << (c <= a ? 0 : ((c - a) * w - b + w - x - 1) / (w - x));
}
