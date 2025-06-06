#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  long long x;
  cin >> x;
  x = (x % 360 + 360) % 360;
  int res{};
  while (!(0 <= x && x <= 45 || 315 <= x && x < 360)) {
    res++;
    x = (x + 270) % 360;
  }
  cout << res << endl;
}
