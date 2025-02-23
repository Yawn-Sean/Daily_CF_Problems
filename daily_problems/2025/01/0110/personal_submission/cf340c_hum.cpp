#include <bits/stdc++.h>
using namespace std;
using i64 = long long;


int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  i64 sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  ranges::sort(a);

  i64 pre_sum = a[0];

  for (int i = 1; i < a.size(); ++i) {
    sum += (1LL * i * a[i] - pre_sum) * 2;
    pre_sum += a[i];
  }
  i64 g = gcd(sum, n);
  cout << sum / g << " " << n / g << endl;
}
