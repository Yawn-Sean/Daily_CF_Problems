#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b, x1, y1, x2, y2;
  cin >> a >> b >> x1 >> y1 >> x2 >> y2;

  auto div = [&](int a, int b) -> int {
    int x = a / b;
    if (b * x > a) x--;
    return x;
  };

  cout << max(abs(div(x1 + y1, 2 * a) - div(x2 + y2, 2 * a)),
              abs(div(x1 - y1, 2 * b) - div(x2 - y2, 2 * b)));

  return 0;
}
