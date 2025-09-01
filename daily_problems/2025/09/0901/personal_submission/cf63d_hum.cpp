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

  int a, b, c, d, n;
  cin >> a >> b >> c >> d >> n;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }
  int N = max(b, d), M = a + c;
  vector grid(N, string(M, '.'));

  for (int i = 0; i < b; i++) {
    for (int j = 0; j < a; j++) {
      grid[i][j] = '?';
    }
  }

  for (int i = 0; i < d; i++) {
    for (int j = 0; j < c; j++) {
      grid[i][a + j] = '?';
    }
  }

  int x{}, y{}, dx{};
  if (a & 1) x = b - 1, y = 0, dx = -1;
  else x = 0, y = 0, dx = 1;

  int pt{};
  for (int i = 0; i < a * b + c * d; i++) {
    if (i) {
      if (x + dx >= 0 && x + dx < N && grid[x + dx][y] == '?') x += dx;
      else y++, dx = -dx;
    }

    while (!nums[pt]) pt++;
    nums[pt]--;

    grid[x][y] = 'a' + pt;
  }

  cout << "YES\n";
  for (auto &line: grid) cout << line << '\n';
}
