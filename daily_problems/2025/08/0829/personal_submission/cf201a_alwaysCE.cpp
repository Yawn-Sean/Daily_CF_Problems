#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int x;
  cin >> x;
  if (x == 3) {
    cout << 5 << endl;
    return 0;
  }
  /*
    f(2) = [0]
    f(3) = [1, 2, (3), 4, 5]
    f(4) = [4]
    f(5) = [1,2,3,4,5,6,7,8,9,10,(11),12,13]
    f(6) = [4, 8]
    1 0 1 0 1
    0 1 0 1 0
    0 0 1 0 0
    0 1 0 1 0
    1 0 1 0 1
    */
  for (int ans = 1;; ans += 2) {
    if ((ans * ans + 1) / 2 >= x) {
      cout << ans << endl;
      return 0;
    }
  }
  return 0;
}
