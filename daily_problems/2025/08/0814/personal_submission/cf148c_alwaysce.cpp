#include <iostream>

using std::cin;
using std::cout;
using std::ios_base;
using std::endl;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, a, b;
  cin >> n >> a >> b;
  if (a > 0 && a == n - 1) {
    cout << -1 << endl;
    return 0;
  } else if (n == 1) {
    cout << 1 << endl;
    return 0;
  } else {
    // wow
    if (b > 0) {
      b--;
      cout << "1 2 ";
    } else {
      cout << "2 1 ";
    }
    int cur = 3, val = 2;
    for (int i = 2; i < n; i++) {
      // first 'wow'
      if (b > 0) {
        b--;
        val = cur + 1;
        cur += val;
      } else if (a > 0) {
        // then ohh
        a--;
        val = val + 1;
      } else {
        val = 1;
      }
      cout << val << " ";
    }
  }
  return 0;
}
