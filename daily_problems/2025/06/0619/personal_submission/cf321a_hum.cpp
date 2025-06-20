#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b;
  cin >> a >> b;

  map<char, pair<int, int>> dirs;
  dirs['U'] = {0, 1};
  dirs['D'] = {0, -1};
  dirs['L'] = {-1, 0};
  dirs['R'] = {1, 0};
  string s;
  cin >> s;
  int x{}, y{};
  for (auto c: s) {
    auto [dx, dy] = dirs[c];
    x += dx;
    y += dy;
  }
  int cur_x{}, cur_y{};
  function<bool()> check = [&]()-> bool {
    int step = 0;
    if (x) {
      step = (a - cur_x) / x;
    }
    if (y) {
      step = (b - cur_y) / y;
    }
    return step >= 0 && cur_x + x * step == a && cur_y + y * step == b;
  };
  for (auto c: s) {
    if (check()) {
      cout << "Yes";
      return 0;
    }
    auto [dx, dy] = dirs[c];
    cur_x += dx;
    cur_y += dy;
  }
  cout << "No";
}
