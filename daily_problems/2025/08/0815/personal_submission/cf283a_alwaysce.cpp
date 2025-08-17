#include <cstdint>
#include <iomanip>
#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::ios_base;
using std::setprecision;
using std::vector;
using i64 = int64_t;
using std::fixed;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;

  vector<int> add = {0};
  vector<int> nums = {0};
  i64 tot = 0;

  for (int i = 1; i <= n; i++) {
    int op;
    cin >> op;
    if (op == 1) {
      i64 a, x;
      cin >> a >> x;
      tot += a * x;
      add[a - 1] += x;
    } else if (op == 2) {
      int k;
      cin >> k;
      add.push_back(0);
      nums.push_back(k);
      tot += k;
    } else {
      tot -= nums.back();
      tot -= add.back();
      add[add.size() - 2] += add.back();
      add.pop_back();
      nums.pop_back();
    }
    cout << fixed << setprecision(10) << (long double)1.0 * tot / nums.size()
         << endl;
  }

  return 0;
}
