#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int r, h;
  cin >> r >> h;
  int res = h / r * 2;
  h %= r;
  if (4ll * h * h >= 3ll * r * r) {
    res += 3;
  } else if (h * 2 >= r) {
    res += 2;
  } else {
    res += 1;
  }
  cout << res << endl;
}
