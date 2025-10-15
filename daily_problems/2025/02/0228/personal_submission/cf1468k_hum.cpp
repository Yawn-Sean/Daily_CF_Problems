#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  map<char, array<int, 2>> m;
  m['L'] = {-1, 0};
  m['R'] = {1, 0};
  m['U'] = {0, 1};
  m['D'] = {0, -1};

  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    int x{}, y{};

    auto check = [&](int cx, int cy, int ox, int oy, int i) {
      for (int j = i; j < n; j++) {
        cx += m[s[j]][0];
        cy += m[s[j]][1];
        if (cx == ox && cy == oy) {
          cx -= m[s[j]][0];
          cy -= m[s[j]][1];
        }
      }
      return cx == 0 && cy == 0;
    };
    bool f{false};
    for (int i = 0; i < n; i++) {
      int nx{x}, ny{y};
      x += m[s[i]][0];
      y += m[s[i]][1];
      if (x == 0 && y == 0) {
        continue;
      }
      if (check(nx, ny, x, y, i + 1)) {
        f = true;
        cout << x << " " << y << "\n";
        break;
      }
    }
    if (!f) {
      cout << 0 << " " << 0 << "\n";
    }
  }
}
