#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k, p, x, y;
  cin >> n >> k >> p >> x >> y;
  vector<int> a(n);
  int sum{}, cnt{};
  for (int i = 0; i < k; ++i) {
    cin >> a[i];
    if (a[i] < y) {
      cnt++;
    }
    sum += a[i];
  }
  vector<int> res;
  int o{n / 2 - cnt};
  if (o < 0) {
    cout << -1 << endl;
    return 0;
  }
  while (o-- && res.size() + k < n) {
    res.push_back(1);
  }
  while (res.size() + k < n) {
    res.push_back(y);
  }
  if (sum + accumulate(res.begin(), res.end(), 0) > x || res.size() + k != n) {
    cout << -1 << "\n";
  } else {
    for (int i = 0; i < n - k; ++i) {
      cout << res[i] << " \n"[i == n - 1];
    }
  }
}
